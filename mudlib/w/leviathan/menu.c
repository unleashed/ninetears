/* Hamlet, March 1996 -- This object displays menus in a VMS HELP-like
                         system.  It must be cloned for each user,
                         And must be told who the user is, where to 
                         enter the menuing system, and what object
                         holds the index for the system.
   Hamlet, Aug 1997   -- Minor reworks to allow the indexing system
                         to be changeable.  Also some minor code fixes.
                      -- Turned into a major project of adding features,
                         making this version 2.0
*/

/* All code copyright 1996 and 1997 by Isaac Charles (baked@potato.org).
   Permission is granted to use, copy, redistribute, and modify this
   code.  Credit must remain, changes should be marked as such.
*/

/* Notes for possible future expansion:
   * Might be useful to have some way to alias menu entries....
     To make meaningless entries into meaningful ones, perhaps.
   * If this were inherited, would be useful to have a way to
     add commands to input_prompt().
   * Possibly support 'man 3 stringp' sort of queries.  Where
     chapters are defined by primary subdir?
*/

#include <colors.h>

inherit "/std/basic/wildcard.c";

/* Very temporary defines.  REPLACE ME */
#define NROFF_HAND this_object()
// #define nroff_file(string x, int y) put actual function name here
// Then remove the line below. 
string nroff_file(string x, int y) { return read_file(x); }

/* Use this if you like to be able to pick entries by number */
#define NUMBERS

/* Maximum documents "man -a <thing>" will display at once. */
#define MAX_SPEW_DOCS 5

/* Message used when a delay is needed. */
#define PRESS_RETURN "[Press return to continue.]"

object user;        /* Display owner */
int MENUING;        /* If we're in the menu system */
object handler;     /* Which index handler */
string index_root;  /* Root directory of this index */ 
int has_merge_dirs; /* If the index merges directories */
string *mergedirs;  /* The merged directories */ 
string *curpath;    /* What directory we're in */
string *view_files; /* Files we have queued for viewing. */
int all_matches;    /* If we want to view all matches. */
int expert;         /* Avoid the help message at the bottom of menus */

/* These are scratchpad sorts of things... 
   keeps us from having to re-query or recalculate. 
*/
string curmenu;
string menu_screen;
string *subdirs;
string *docs;
string *other_matches;
int cols, rows;

varargs void show_menu(string file, int redisplay);
void show_document(string file);
void show_mult_documents(string *thedocs);
void input_prompt(string str);
void delay_prompt(string str);
void menu_prompt(string str);
string insert_mergetext(string text, string fname);
void dest_me();

#ifdef NUMBERS
string *match_by_number(string str);
#endif

varargs void do_query(mixed hand, string str, object me, int match_all, 
                      int enter_menu, int menu_expert, int reenter) {
  string *bits;
  int building;
  string *fnames;
  string *dir_wants = ({ });
  string *doc_wants = ({ });
  int is_directory;
  int i, j;

  if(!reenter) { /* Most checks and assignments can be skipped if
                    we're reentering from somewhere else in the system. */  
    user = me;

    if(stringp(hand))
      if(catch(hand = load_object(hand))) {
        tell_object(user, "The handler for this system is broken.  "
                          "Please inform someone who can fix it.\n");
        dest_me();
        return;
      }

    building = hand->doc_index_building();
  }

  if(!str)
    str = "";
  else {
    bits = explode(str," ") - ({ "" });

    if(sizeof(bits) > 1)
      str = implode(bits,"/");

    str = replace_string(str, ",/", ","); /* fix for "blah, blah2" */
  }

  fnames = hand->get_doc_fnames(str);
  
  if(!sizeof(fnames)) {
    tell_object(user,"Your subject was not found in the index.\n");
    if(reenter) {
      tell_object(user,PRESS_RETURN);
      input_to("delay_prompt");
      return;
    }
    else if(building)
      tell_object(user,"However, the system is currently loading.  "
                  "Try again in a few seconds.\n");
    dest_me();
    return;
  }

  if(!reenter) {
    mergedirs = hand->get_mergedirs();
    if(sizeof(mergedirs))
      has_merge_dirs = 1;
  }

  /* Okay!  We've got a match.  Do we enter the menuing system or
     just display a page?
  */
  i = member_array("", fnames);

  if(match_all || (i > MAX_SPEW_DOCS))
    fnames -= ({ "" });
  else {
    if(i > -1) {
      if(!has_merge_dirs)
        other_matches = fnames[i+1..];
      else {
        other_matches = ({ });
        for(j=i+1; j < sizeof(fnames); j++)
          other_matches += ({ implode(explode(fnames[j], "/")[1..], "/") });
      }

      other_matches = sort_array(other_matches, 1);
      fnames = fnames[0..i-1];
    }
  }

  for(i=0; i < sizeof(fnames); i++)
    if(fnames[i][<6..<1] == "README")
      dir_wants += ({ fnames[i] });
    else
      doc_wants += ({ fnames[i] });

  if(!reenter) {
    handler = hand;
    index_root = hand->get_index_root(user);

    all_matches = match_all;

    if(menu_expert)
      expert = 1;
    else if(user->query_property("MENU_EXPERT"))
      expert = 1;

    rows = user->query_rows();
    cols = user->query_cols();
  }

  if(!sizeof(dir_wants) && (sizeof(doc_wants) <= MAX_SPEW_DOCS)) { 
    /* Show them all the docs */
    if(enter_menu || (reenter == '^')) {
      if(building) {
        tell_object(user,"The menu system is currently loading.  "
                    "Please wait a few seconds.\n");
        dest_me();
        return;
      }
      doc_wants += ({ hand->get_doc_fnames(implode(explode(
                        doc_wants[<1], "/")[has_merge_dirs..<2], "/"))[0] });
      MENUING = 1;
    }
    show_mult_documents(doc_wants);

  }
  else if((!sizeof(doc_wants) && (sizeof(dir_wants) == 1))) {
    if(building) {
      tell_object(user,"The menu system is currently loading.  "
                  "Please wait a few seconds.\n");
      dest_me();
      return;
    }
    else
      MENUING = 1;

    bits = explode(dir_wants[0], "/");

    if(sizeof(bits) == (has_merge_dirs + 1))
      curpath = ({ });
    else
      curpath = bits[has_merge_dirs..<2];    
    
    curmenu = dir_wants[0];

    show_menu(curmenu);
  }
  else { /* Mixed bag.  Fake a menu for them to pick better. */
    curpath = ({ });

    for(i = 0; i < sizeof(dir_wants); i++)
      dir_wants[i] = implode(explode(
                       dir_wants[i], "/")[has_merge_dirs..<2], "/");
    if(has_merge_dirs)
      for(i = 0; i < sizeof(doc_wants); i++)
        doc_wants[i] = implode(explode(
                         doc_wants[i], "/")[1..], "/");

    if(sizeof(other_matches)) {
      for(i=0; i < sizeof(other_matches); i++)
        if(other_matches[i][<6..<1] == "README")
          dir_wants += ({ other_matches[i] });
        else
          doc_wants += ({ other_matches[i] });
      other_matches = 0;
    }

    subdirs = sort_array(dir_wants,1);
    docs = sort_array(doc_wants,1);
    curmenu = "_FAKE_README";
    MENUING = 1;

    show_menu(curmenu, -1);
  }
}

/* This one shows both a directory's doc file (dir/README) and a list
   of available documents and subtopics in the dir.  It relies on 
   curpath being properly set.
*/
varargs void show_menu(string file, int redisplay) {
  string ftext;
  int i;
  string *thesubdirs;
  string *thedocs;

  if((redisplay != 1) || !menu_screen) {
    if(file_size(index_root + file) > 0)
      ftext = insert_mergetext(NROFF_HAND->nroff_file(index_root + file, 
                                                      cols), file);
    else if(file_size(index_root + "_NO_README") > 0)
      ftext = NROFF_HAND->nroff_file(index_root + "_NO_README", cols);
    else
      ftext = "This directory has no description.\n";

    if(redisplay != -1) {
      subdirs = handler->get_subdirs(implode(curpath,"/"));
      docs = handler->get_docs_in_dir(implode(curpath,"/"));
    }

    if(sizeof(curpath))
      menu_screen = MTOPIC_COLOR + "Topic: "+implode(curpath,"/")+
             "%^RESET%^\n\n";
    else
      menu_screen = "";
    
    menu_screen += ftext+"\n";

#ifdef NUMBERS
    thesubdirs = allocate(sizeof(subdirs));
    thedocs = allocate(sizeof(docs));

    for(i=0; i < sizeof(subdirs); i++)
       thesubdirs[i] = (i + 1) + ") " + subdirs[i];
    for(i=0; i < sizeof(docs); i++)
       thedocs[i] = (i + sizeof(subdirs) + 1) + ") " + docs[i];
#else
    thesubdirs = subdirs;
    thedocs = docs;
#endif

    if(sizeof(thesubdirs))
      menu_screen += "Subtopics:\n\n" + MSUBTOP_COLOR + 
              sprintf("  %-#*s", cols,
              implode(thesubdirs,"\n"))+"\n\n%^RESET%^";
    if(sizeof(thedocs))
      menu_screen += "Documents:\n\n" + MDOC_COLOR +
              sprintf("  %-#*s", cols,
              implode(thedocs,"\n"))+"\n\n%^RESET%^";
    if(sizeof(other_matches)) {
      menu_screen += MTOPIC_COLOR + sprintf("*Other topics: %-=*s\n\n", 
                     (cols - 15), implode(other_matches, ", ")) +
                     "%^RESET%^";
      other_matches = 0;
    }

    if(!expert)
      menu_screen += "Type 'q' to quit, 'h' for help.  Enter subtopic "
            "or document to continue.\n'.' will redisplay this menu.  "
            "Press <ret> to go one level lower.\n";
 
  }

  if(sizeof(explode(menu_screen,"\n")) < (rows-1)) {
    tell_object(user, menu_screen);
    menu_prompt(0);
  }
  else {
    user->set_finish_func("menu_prompt");
    user->more_string(menu_screen,"[Menu]");
  }
}

/* This one displays a document, more'ing it if necessary. */
void show_document(string file) {
  string *fdata;
  string topic;
  string data;
  
  if(file_size(index_root + file) <= 0) {
    tell_object(user,"Oops.  That file seems to be empty.\n" +
                PRESS_RETURN);
    input_to("delay_prompt");
    return;
  }
  else {
    fdata = explode(file,"/") - ({ "" });
    if(has_merge_dirs)
      topic = implode(fdata[1..], "/");
    else
      topic = file;

    if(sizeof(fdata[has_merge_dirs..]))
      data = "\n" + MTOPIC_COLOR + "Topic: "+topic+"%^RESET%^\n\n";
    else
      data = "\n";

    data += insert_mergetext(NROFF_HAND->nroff_file(index_root + file,
                                                    cols), file);

    if(!sizeof(view_files) && sizeof(other_matches)) {
      data += MTOPIC_COLOR + sprintf("*Other topics: %-=*s\n\n", 
              (cols - 15), implode(other_matches, ", ")) +
              "%^RESET%^";
      other_matches = 0;
    }

    if(sizeof(explode(data,"\n")) < (rows-1)) {
      tell_object(user,data+"\n");
      if(MENUING || sizeof(view_files)) {
        tell_object(user,PRESS_RETURN);
        input_to("delay_prompt");
      }
      else
        dest_me();
      return;
    }
    else {
      user->set_finish_func("finish_func");
      user->more_string(data,"["+topic+"]");
    }
  }
}

/* This one loops around (with the help of finish_func) showing
   more than one document.
*/
void show_mult_documents(string *thedocs) {
  string *bits;

  view_files = thedocs[1..];

  /* The last document could conceivably actually be a directory. */
  if((sizeof(thedocs) == 1) && (thedocs[0][<6..<1] == "README")) {
    bits = explode(thedocs[0], "/");

    if(sizeof(bits) == (has_merge_dirs + 1))
      curpath = ({ });
    else
      curpath = bits[has_merge_dirs..<2];    
    
    curmenu = thedocs[0];
    show_menu(curmenu);
  }
  else
    show_document(thedocs[0]);
}

void menu_prompt(string str) {
  tell_object(user, MTOPIC_COLOR + "/" + implode(curpath,"/") + 
                    ">%^RESET%^ ");
  input_to("input_prompt");
}

/* Called when they press <ret> after viewing something. */
void delay_prompt(string str) {
  if(str == "Q")
    view_files = 0;

  if(sizeof(view_files))
    show_mult_documents(view_files);
  else if(MENUING)
    show_menu(curmenu,1);
  else
    dest_me();
}

/* Called when more_string() gets done. */
varargs void finish_func(string lvl) {
  if(lvl || (!MENUING && !sizeof(view_files)))
    delay_prompt(lvl);
  else {
    tell_object(user,PRESS_RETURN);
    input_to("delay_prompt");
  }
}

void input_prompt(string str) {
  int i;
  string doc;
  int match_type;
  string *matches;
  string *tmp;
  string errmsg;

  if(!str)
    str = "";

  /* Command processing first */
  switch(str) {
    case ""      :
    case ".."    :
    case "cd .." : /* Drop a level. */
                   if(!sizeof(curpath)) { /* exit the system */
                     dest_me();
                     return;
                   }
    
                   /* Otherwise, just go one directory shallower */
                   if(sizeof(curpath) == 1)
                     curpath = ({ });
                   else
                     curpath = curpath[0..<2];
      
                   curmenu = handler->get_doc_fnames(
                                        implode(curpath,"/"))[0];
                   show_menu(curmenu);
                   return;

    case "q"     : /* They're quitting the system. */
                   dest_me();
                   return;

    case "h"     : /* They want menu help. */
                   show_document("_MENU_HELP");
                   return;

    case "H"     : /* They want examples */
                   show_document("_EXAMPLES");
                   return;
  
    case "."     : /* Redisplay menu */
                   show_menu(curmenu,1);
                   return;

    case "+x"    : /* Menu expert */
                   user->add_property("MENU_EXPERT", 1);
                   expert = 1;
                   menu_screen = 0;
                   tell_object(user, "You will no longer see the "
                     "help lines at the bottom of menus.\n" + 
                     PRESS_RETURN);
                   input_to("delay_prompt");
                   return;

    case "-x"    : /* Menu novice */
                   user->remove_property("MENU_EXPERT");
                   expert = 0;
                   menu_screen = 0;
                   tell_object(user, "You will again see the help "
                     "lines at the bottom of menus.\n" +
                     PRESS_RETURN);
                   input_to("delay_prompt");
                   return;
  }

  /* else */
  if((str[0] == '@') || (str[0] == '^')) { 
    /* They want to jump elsewhere in the system */
    do_query(handler, str[1..], user, all_matches, 0, expert, str[0]);
    return; 
  }

#ifdef NUMBERS
  /* else, they may be picking by number(s) */
  matches = match_by_number(str);

  if(sizeof(matches)) {
    if(member_array(matches[0],docs) > -1)
      match_type = 'd';
    else
      match_type = 's';
  }
#endif

  /* else, this is a real attempt to view a subtopic or document. */
  /* First, we look for exact matches. */
  if(!sizeof(matches)) {
    i = member_array(str,subdirs);

    if(i > -1) { 
      match_type = 's'; /* subdir */
      matches = ({ subdirs[i] });
    }
    else {
      i = member_array(str,docs);
      if(i > -1) {
        match_type = 'd'; /* doc */
        matches = ({ docs[i] });
      }
      else { /* here's where it gets tricky.  We're going back and
                trying for UNIX-type wildcards */
        /* need to "translate" wildcard-speak into regexp. */
        str = wild2regexp(str,1);

        if(errmsg = catch(matches = regexp(docs, str))) {
          tell_object(user, errmsg + "\n\n" + PRESS_RETURN);
          input_to("delay_prompt");
          return;
        }

        if(sizeof(matches))
          match_type = 'd';
        else if(sizeof(matches = regexp(subdirs,str)))
          match_type = 's';
        else { /* nothing valid was typed, whatsoever. */
          tell_object(user,"That selection is not valid.\n\n" + 
                      PRESS_RETURN);
          input_to("delay_prompt");
          return;
        }

        /* Does a stricter exact-wildcard match leave us with anything?
           The above allowed sloppy end-of-string things.
        */
        if(sizeof(tmp = regexp(matches, (str + "$"))))
          matches = tmp;
      }
    }
  }

  /* crap out immediately if they matched multiple subdirs. */
  if((sizeof(matches) > 1) && (match_type == 's')) {
     tell_object(user, "Your query matches multiple subtopics.\n\n" +
                       PRESS_RETURN);
     input_to("delay_prompt");
     return;
  }

  if(match_type == 'd') {
    for(i=0; i < sizeof(matches); i++) {
      if(sizeof(curpath))
        doc = implode(curpath,"/") + "/" + matches[i];
      else
        doc = matches[i];
      matches[i] = handler->get_doc_fnames(doc)[0];
    }
    show_mult_documents(matches); 
  }
  else { /* They want to view a new directory */
    if(sizeof(curpath))
      doc = implode(curpath,"/") + "/" + matches[0];
    else
      doc = matches[0];
    curmenu = handler->get_doc_fnames(doc)[0];
    curpath += explode(matches[0], "/");
    show_menu(curmenu);
  }
}

/* Takes text of a file and its mergedir and inserts text from
   a "lower" mergedir in the location denoted by:
    #*(mergedir)#*

   If the entry is merely #*#*, the next lower mergedir is used
   that has a copy of the file.

   If form is #*[/path/to/file]#* it's an absolute path.
   If form is #*[path/to/file]#*, it's relative to index root.
   If form is #*[file]#*, it's in the current dir.
*/
string insert_mergetext(string text, string fname) {
  string begin, mid, end;
  int curdir, wantdir;
  string newfile, genfile;
  string ret = text;
  string *tmp, *tmp2;
  int FOUND;

  tmp = explode(fname, "/");
  genfile = implode(tmp[1..], "/");
  curdir = member_array(tmp[0] + "/", mergedirs);
 
  while(sscanf(ret, "%s#*%s#*%s", begin, mid, end)) {
    FOUND = 0;

    if(mid[0] == '[') {
      if(strsrch(mid, '/') == -1) { /* in current dir */
        tmp2 = handler->get_doc_fnames(implode(tmp[1..<2], "/") + 
                                       mid[1..<2]);
        if(sizeof(tmp2)) {
          FOUND = 1;
          newfile = index_root + tmp2[0];
        }
      }
      else if(mid[1] != '/') { /* path inside man system */
        tmp2 = handler->get_doc_fnames(mid[1..<2]);
        if(sizeof(tmp2)) {
          FOUND = 1;
          newfile = index_root + tmp2[0];
        }
      }
      else /* full path */
        if(file_size(mid[1..<2]) > 0) {
          FOUND = 1;
          newfile = mid[1..<2];
        }
    }
    else if(has_merge_dirs && (curdir < (sizeof(mergedirs) - 1))) { 
      /* We're messing with mergedirs */
      if(!strlen(mid)) { /* next lowest match */
        for(wantdir = curdir + 1; wantdir < sizeof(mergedirs); wantdir++)
          if(file_size(index_root + mergedirs[wantdir] + genfile) > 0) {
            FOUND = 1;
            newfile = index_root + mergedirs[wantdir] + genfile;
            break;
          }
      }
      else if(mid[0] == '(') {
        wantdir = member_array(mid[1..<2] + "/", mergedirs);
        if((wantdir > -1) && (wantdir > curdir) &&
           (file_size(index_root + mergedirs[wantdir] + genfile) > 0)) {
          FOUND = 1;
          newfile = index_root + mergedirs[wantdir] + genfile;
        }
      }
    }

    if(FOUND)
      ret = replace_string(ret, "#*" + mid + "#*", 
              insert_mergetext(NROFF_HAND->nroff_file(newfile, cols), 
                               newfile));
    else
      ret = replace_string(ret, "#*" + mid + "#*", "");
  }

  return ret;
}

#ifdef NUMBERS
/* Takes a space-separated list of numbers and translates them
   into associated documents.  If there is non-numerical
   text in the list, it'll just bomb out.  If there is *one*
   subtopic, it'll return a list of any documents and that
   one subtopic at the end.  Otherwise, it either returns
   just the documents, or, if none, just the directories.
*/
string *match_by_number(string str) {
  string *list_docs = ({ });
  string *list_subdirs = ({ });
  string *tmp;
  int i, num;

  tmp = explode(str, " ") - ({ "" });

  for(i=0; i < sizeof(tmp); i++)
    if((num = atoi(tmp[i])) && ((num + "") == tmp[i])) {
      if(num <= sizeof(subdirs))
        list_subdirs += ({ subdirs[num - 1] });
      else if(num <= (sizeof(subdirs) + sizeof(docs)))
        list_docs += ({ docs[num - sizeof(subdirs) - 1] });
      /* else index is out of range.  We'll just ignore it. */
    }
    else /* They entered something alphabetic or otherwise odd */
      return ({ });

  if(sizeof(list_subdirs) == 1)
    return list_docs + list_subdirs;
  else if(sizeof(list_docs))
    return list_docs;
  else
    return list_subdirs;
}
#endif

void create() {
  seteuid(getuid());
  curpath = ({ });
  MENUING = 0;  /* paranoia */
}

void dest_me() {
  destruct(this_object());
}

void reset() {
  if(!user && clonep(this_object()))
    dest_me();
}

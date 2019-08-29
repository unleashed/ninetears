/* Hamlet, March 1996.  -- This holds an index for a menuing system,
                           basically.  Inheritable code.  Calleables
                           are at the top.
 * Major rework (to make it inheritable, and some added features)
   by Hamlet, Aug 1997, making this version 2.0
*/

/* All code copyright 1996 and 1997 by Isaac Charles (baked@potato.org).
   Permission is granted to use, copy, redistribute, and modify this
   code.  Credit must remain, changes should be marked as such.
*/

inherit "/std/basic/wildcard.c";

/* This one will store the directory structure as mappings within mappings.
   Will be used for the browsing system.
   The actual documents in the directory will be stored with an index
   of "." as an array.
*/
private mapping directories;

/* This one will be of the form  "document" : ({ "where/to/find",
    "where/else/to/find" }) for specific queries.  If the document 
   is the name of a directory, dir/README will be in the list.
*/
private mapping files;

/* this is the same list as above, except the "full path" to
   the file is used as an index.
*/
private mapping path_files;

/* This is used to keep work-in-progress during startup. */
private string *todo;
private static mapping global_aliases;

private static string index_root;    /* "Root directory" */
private static string *mergedirs;    /* Dirs under root to be merged */
private static string save_file;     /* For save_object() */
private static int no_file_security; /* All docs will be readable by all */
private static string g_alias_file;  /* Holds global aliases */

private static void sort_manual_dirs();
private mapping get_doc_dir(string dirname);
private static varargs void create(int recreate);
varargs int readable(string file, string path);

/* ****** These should be set in setup() of an inheritor. ****** */

/* Required call. */
nomask void set_index_root(string root) {
  string *tmp;

  tmp = explode(root, "/") - ({ "" });

  index_root = "/" + implode(tmp, "/") + "/";
}

/* Using this is optional.  Order the directories in decreasing
   relevance.  i.e. if a file appears in both mergedirs, which
   one will be used?
*/
nomask void set_mergedirs(string *dirs) {
  int i;

  if(!dirs || !arrayp(dirs) || !sizeof(dirs)) {
    mergedirs = ({ "" });
    return;
  }

  for(i = 0; i < sizeof(dirs); i++)
    if(dirs[i][<1] != '/')
      dirs[i] += "/";

  mergedirs = dirs - ({ "" });
}

nomask void set_save_file(string fname) {
  if((fname[<2..<1] == ".c") || (fname[<2..<1] == ".o"))
    save_file = fname[0..<3];
  else
    save_file = fname;
}

nomask void remove_file_security() {
  no_file_security = 1;
}

nomask void set_global_alias_file(string fname) {
  if(strsrch(fname, '/') == -1)
    g_alias_file = index_root + fname;
  else
    g_alias_file = fname;
}

/* ****** These are the things that can be queried. ****** */

string get_index_root() { return copy(index_root); }

string *get_mergedirs() { return (mergedirs - ({ "" })); }

/* This should receive a docname either in the form  path/file or file. */
string *get_doc_fnames(string docname) {
  string *matches;
  string *tmp;
  string *prim = ({ });
  string *secnd = ({ });
  string thedoc, adoc;
  int i;
  mapping t;

  if(!docname || !strlen(docname))
    return ({ "local/README" });

  if(path_files[docname])
    return filter(path_files[docname], (: readable :));
    
  if(files[docname])
    return filter(files[docname], (: readable :));

  /* More complex wildcard matching. */
  thedoc = wild2regexp(docname, 1);
  
  if(catch(matches = regexp(keys(files), thedoc))) {
    return ({ });
  };

  if(sizeof(matches))
    t = files; 
  else {
    matches = regexp(keys(path_files), thedoc);

    if(sizeof(matches))
      t = path_files;
    else
      return ({ });
  }

  if(sizeof(tmp = regexp(matches, thedoc + "$")))
    matches = tmp;

  foreach(adoc in matches) {
    i = member_array("", t[adoc]);

    if(i == -1)
      prim += t[adoc];
    else {
      prim += t[adoc][0..i-1];
      secnd += t[adoc][i+1..];
    }
  }

  return prim + ({ "" }) + secnd;
}

string *get_subdirs(string dirname) {
  mapping t;
  
  t = get_doc_dir(dirname);
  
  if(!t || !sizeof(t))
    return ({ });
    
  return sort_array(filter(keys(t) - ({ "." }), 
                           (: readable :), dirname), 1);
}

string *get_docs_in_dir(string dirname) {
  mapping t;
  
  t = get_doc_dir(dirname);
  
  if(!t || !sizeof(t))
    return ({ });
    
  return filter(t["."], (: readable :), dirname);
}

/* Is the index currently being built? */
int doc_index_building() {
  if(!todo)
    return 1;
  if(!sizeof(todo))
    return 0;
    
  return 1;
}

/* Diagnostics.  If these are different sizes, you have 
   name-collisions somewhere.  Not the greatest thing, but 
   I guess it can be lived with.
*/
int size_of_files() {  return sizeof(files);  }
int size_of_path_files() {  return sizeof(path_files);  }

/* ****** These rebuild the index ****** */

/* This one updates everything in the event that you've added pages. */
void rebuild() {
  create(1);
}

/* ****** Internal functions ****** */

/* Mask this one if some of your tree is viewable only by a 
   certain group.  if(path), the full filename is:
     index_root + path + "/" + file
   else, the full filename is:
     index_root + file
   Also, the file named "" should always be considered readable.
   It might be wise to do if(::readable(file, path)) somewhere in
     your function (keeps people from having choices they can't
     read anyway)
*/
varargs int readable(string file, string path) {
  if(no_file_security)
    return 1;

  if(file == "")
    return 1;

  if(path)
    return master()->valid_read(index_root + path + "/" + file, 
                                this_player(), "readable");
  else 
    return master()->valid_read(index_root + file, this_player(), 
                                "readable");
}

private mapping get_doc_dir(string dirname) {
  string *tmp;
  mapping t;
  int i;
  
  if(!dirname || !strlen(dirname))
    return directories;
    
  tmp = explode(dirname,"/") - ({ "" });
  t = directories;
  
  for(i=0;i<sizeof(tmp);i++) {
    t = t[tmp[i]];
    if(!t)
      break;
  }
    
  return t;
}

void init_global_aliases() {
  string *lines, *words;
  int i;

  global_aliases = ([ ]);

  if(!g_alias_file || (file_size(g_alias_file) <= 0))
    return;

  lines = explode(read_file(g_alias_file), "\n");

  for(i=0; i<sizeof(lines); i++) {
    if(strlen(lines[i]) && (lines[i][0] != '#')) {
      words = explode(lines[i], " ") - ({ "" });
      if(sizeof(words) < 3)
        continue;

      if(!global_aliases[words[0]])
        global_aliases[words[0]] = words[2..];
      else
        global_aliases[words[0]] += (words[2..] - global_aliases[words[0]]); 
    }
  }
}

/* This one builds the document data. */
private nomask void sort_manual_dirs() {
  string *dirs;
  int i,j,k,m, a;
  string *f;
  string *tmp, *tmp2, *tmp3;
  mapping t, aliases;
  int sz;
  string *newtodo = ({ });

  if(!index_root) /* Improperly defined indexer */
    return;
  
  if(!todo)  /* The system is just starting up... */
    todo = ({ "" });
  else if(!sizeof(todo))
    return;

  for(k=0;k<sizeof(todo);k++) {
    f = ({ });
    dirs = ({ });
    tmp = ({ });
    aliases = ([ ]);

    for(i=0;i<sizeof(mergedirs);i++) {
      tmp2 = get_dir(index_root+mergedirs[i]+todo[k]);

      if(tmp2)
        tmp += (tmp2 - tmp);

      if(index_root+mergedirs[i]+todo[k] == index_root)
        /* remove files beginning with '_' in the index_root dir */
        for(j=0; j<sizeof(tmp2); j++)
          if((tmp2[j][0] == '_') && (tmp2[j] != "_ALIASES"))
            tmp -= ({ tmp2[j] });

      if((member_array("_ALIASES", tmp2) > -1) &&
         (file_size(index_root+mergedirs[i]+todo[k]+"_ALIASES") > 0)) {
        tmp2 = explode(
                 read_file(index_root+mergedirs[i]+todo[k]+"_ALIASES"),
                 "\n" );
        for(j=0; j<sizeof(tmp2); j++) {
          if(!strlen(tmp2[j]) || (tmp2[j][0] == '#'))
            continue;
          tmp3 = explode(tmp2[j], " ") - ({ "" });
          if(sizeof(tmp3) < 3)
            continue;
          if(!aliases[tmp3[0]])
            aliases[tmp3[0]] = tmp3[2..];
          else
            aliases[tmp3[0]] += (tmp3[2..] - aliases[tmp3[0]]); 
        }
      }
    }

    tmp -= ({ "_ALIASES" });

    for(i=0;i<sizeof(tmp);i++) {
      if(tmp[i][<6..<1] == "README")
        continue; /* We'll deal with these later. */

      if(!aliases[tmp[i]])
        aliases[tmp[i]] = ({ });
      aliases[tmp[i]] += ({ tmp[i] });

      if(global_aliases[tmp[i]])
        aliases[tmp[i]] += global_aliases[tmp[i]];
      
      for(j=0;j<sizeof(mergedirs);j++)
        if((sz = file_size(index_root+mergedirs[j]+todo[k]+tmp[i])) != -1)
          break;
      if(sz == -2) { /* It's a directory */
        for(m=0;m<sizeof(mergedirs);m++)  /* Find the README */
          if(file_size(index_root+mergedirs[m]+todo[k]+tmp[i]+"/README") >= 0)
            break;
        
        if(m == sizeof(mergedirs))
          m = 0;

        for(a=0; a < sizeof(aliases[tmp[i]]); a++) {
          if(!files[aliases[tmp[i]][a]])
            files[aliases[tmp[i]][a]] = 
                ({ mergedirs[m]+todo[k]+tmp[i]+"/README", "" });
          else
            files[aliases[tmp[i]][a]] += 
                ({ mergedirs[m]+todo[k]+tmp[i]+"/README" });
          if(!path_files[todo[k]+aliases[tmp[i]][a]])
            path_files[todo[k]+aliases[tmp[i]][a]] = 
                ({ mergedirs[m]+todo[k]+tmp[i]+"/README", "" });
          else
            path_files[todo[k]+aliases[tmp[i]][a]] += 
                ({ mergedirs[m]+todo[k]+tmp[i]+"/README" });
        }
        newtodo += ({ todo[k]+tmp[i]+"/" });
        dirs += ({ tmp[i] });
      }
      else { /* It's a document. */
        for(a=0; a < sizeof(aliases[tmp[i]]); a++) {
          if(!files[aliases[tmp[i]][a]])
            files[aliases[tmp[i]][a]] = 
                ({ mergedirs[j]+todo[k]+tmp[i], "" });
          else
            files[aliases[tmp[i]][a]] += 
                ({ mergedirs[j]+todo[k]+tmp[i] });
          if(!path_files[todo[k]+aliases[tmp[i]][a]])
            path_files[todo[k]+aliases[tmp[i]][a]] = 
                ({ mergedirs[j]+todo[k]+tmp[i], "" });
          else
            path_files[todo[k]+aliases[tmp[i]][a]] += 
                ({ mergedirs[j]+todo[k]+tmp[i] });
        }
        f += ({ tmp[i] });
      }
    }
    
    tmp = explode(todo[k],"/") - ({ "" });
    t = directories;
    for(i=0;i<sizeof(tmp);i++)
      t = t[tmp[i]];
    
    for(i=0;i<sizeof(dirs);i++)
      t[dirs[i]] = ([ ]);
    t["."] = sort_array(f, 1); 
  }
  
  todo = newtodo;
  
  if(sizeof(todo))
    call_out("sort_manual_dirs",2);
  else {
    global_aliases = ([ ]);
    if(save_file)
      save_object(save_file);
  }
} 

private static varargs void create(int recreate) {
  if(!recreate) {
    seteuid(master()->creator_file(file_name(this_object())));
    this_object()->setup();

    if(!mergedirs)  mergedirs = ({ "" });

    if(!save_file || !restore_object(save_file) || sizeof(todo) ||
       !sizeof(files))
      recreate = 1;
  }

  if(recreate) {
    directories = ([ ]);
    files = ([ ]);
    path_files = ([ ]);
    todo = ({ "" });
    init_global_aliases();
    call_out("sort_manual_dirs", 2);
  }
}

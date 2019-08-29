/* Hamlet -- Apr 1996
   Finds a filename, given a starting path. 
*/

/* This gets cloned to actually do the search. */
#define FINDFILE_OB "/global/creator/cmds/obj/findfile_ob.c"

/* This makes it so only one search can be done per person at a time. */
#define ONE_PER_PERSON 1

/* This makes it so only one search can be performed on the mud at once. */
#define ONE_ONLY 1

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
  position = 1;
}

string query_usage() {
  return "findfile [-a] [<path>] <filename>\n"
         "       findfile HALT\n";
}

string query_short_help() { 
  return "Find a file in the mud's filesystem.\n"
         "If -a is specified, all matches will be shown.  Otherwise only "
                           "the first set is shown.\n\n"
         "examples:\n"
         "  findfile narg.c            -- it will look for narg.c "
                                          "starting with /\n"
         "  findfile -a /w bing.c      -- return all matches to bing.c "
                                          "in /w\n"
         "  findfile /w/hamlet narg.c  -- look for narg.c starting "
                                          "with /w/hamlet\n\n"
         "'findfile HALT' will cancel all current searches.\n\n"
         "NOTE:  Searching for a file is a very costly procedure.\n"
         "       Try to be as specific as possible with the "
                                     "starting directory.\n"
         "       Use the -a option only if there's a need.\n";
         
}

int do_halt(object per);
int check_rules(object per);
string show_findfile_users();

static int cmd(string str, object me) {
  object findfile_ob;
  string *args;
  string path, fname;
  string *files;
  int ALL_MATCHES = 0;
  
  notify_fail("usage: findfile [-a] [<path>] <filename>\n");

  if(!str)
    return 0;

  if(str == "HALT") {
    tell_object(me,do_halt(me)+" searches halted.\n");
    return 1;
  }

  if(str == "USERS") {
    tell_object(me,"Findfile users: "+show_findfile_users()+"\n");
    return 1;
  }
    
  if(!check_rules(me))
    return 1;
    
  if(str[0..2] == "-a ") {
    ALL_MATCHES = 1;
    str = str[3..strlen(str)-1];
  }
  
  args = explode(str," ");
  if(sizeof(args) == 1) {
    path = "/";
    fname = args[0];
  }
  else {
    path = args[0];
    if(path[strlen(path)-1..strlen(path)-1] != "/")
      path += "/";
    fname = args[1];
  }

  files = me->get_files(path);
  
  if(!sizeof(files)) {
    tell_object(me, "findfile: that path was invalid.\n");
    return 1;
  }

  if(!(findfile_ob = clone_object(FINDFILE_OB))) {
    tell_object(me,"The finding object wouldn't clone.  tell someone.\n");
    return 1;
  }
  
  tell_object(me,"Searching...\n");
  findfile_ob->find_file(me,path,fname,ALL_MATCHES);

  return 1;
}

int do_halt(object per) {
  int i;
  object *them;
  int ret = 0;
  
  them = children(FINDFILE_OB);
  
  for(i=0;i<sizeof(them);i++)
    ret += them[i]->HALT(per);
    
  return ret;
}

int check_rules(object per) {
  int i;
  object *them;
  object searcher;

  them = children(FINDFILE_OB);
 
  for(i=0;i<sizeof(them);i++) {
    searcher = them[i]->PERSON_RUNNING_SEARCH();
    
    if( (searcher == per) && ONE_PER_PERSON ) {
      tell_object(per,"You are currently running a search.  Wait until "
                      "it finishes.\n");
      return 0;
    }
    if( searcher && ONE_ONLY ) {
      tell_object(per,"Someone is currently conducting a search.  Wait "
                      "until it finishes.\n");
      return 0;
    }
  }
      
  return 1;
}

string show_findfile_users() {
  object *them;
  
  them = children(FINDFILE_OB)->PERSON_RUNNING_SEARCH();
  
  them -= ({ 0 });
  
  return query_multiple_short(them);
}

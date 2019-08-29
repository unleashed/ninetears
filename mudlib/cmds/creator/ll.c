// /global/creator/cmds/ll.c  --  does an ll
// Isthar@Aurora 9-jan-1995

#include <cmd.h>

inherit CMD_BASE;

void setup() { position = CREATOR_CMD; }

string query_usage() { return "[directory|filename]"; }

string query_short_help() {
 return "Full list files in current or specified directories";
}

static int cmd(string arg, object me){
string *list;
string euid, file;
object obj;
int i, size, date, num_child;

  if (!arg || arg=="") arg=this_player()->query_path()+"/";
  arg = this_player()->get_path(arg);
  if (file_size(arg)==-2 && arg[strlen(arg)-1]!='/') arg+="/";
  list=get_dir(arg,-1);
  for (i=0; i<sizeof(list); i++) {
    if (obj=virtual_find_object(file=arg+list[i][0])) {
      euid=geteuid(obj);
      write(sprintf("%-18s","("+euid+","+sizeof(children(file))+")"));
    } else write(sprintf("%-18s","----------"));
    if (list[i][1]==-2) write(sprintf("%8s","<dir>"));
    else write(sprintf("%8d",list[i][1]));
    write(" "+ctime(list[i][2]));
    write(" "+list[i][0]);
    write("\n");
  }
  return 1;
}

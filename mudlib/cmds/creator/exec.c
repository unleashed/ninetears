#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}



static int cmd(string str, object me) {
  mixed  err, ret;
  object ob;
  string file, wiz_dir;

  if (!this_player()) return 0;
  if (this_player(1) != this_player()) return 0;
  if (!str) {
    notify_fail("usage:  exec <lpc code>\n");
    return 0;
    }
  wiz_dir = "/w/" + (string)this_player()->query_name();
  if (file_size(wiz_dir)!=-2) {
    notify_fail("Directory: " + wiz_dir + " does not exist.\n");
    return 0;
    }
  file = wiz_dir + "/exec_tmp";
  if (find_object(file)) file->dest_me();

  if (file_size(file+".c")>0) rm(file+".c");
  write_file(file+".c",
    "create() { seteuid(geteuid(this_player())); }\n" +
    "dest_me() { destruct(this_object()); }\n" +
    "do_call() {\n"+ str + ";\n}\n");
  err = catch(ret = (mixed) file->do_call());
  if (err==0) printf("\nReturns: %O\n", ret);
  if (find_object(file)) file->dest_me();
  rm(file+".c");

  log_file("XEC", ctime(time()) + " " + (string)this_player()->query_name()+
           " executed : " + str + "\n");
  return 1;
} /* execute() */
 

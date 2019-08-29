#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

position = 1;
}

static int cmd(string str, object me) {
    object ob;
    string err, *filenames;
    int loop, mov;

    if (!str) {
        notify_fail("Clone what ?\n");
        return 0;
    }

    filenames = this_player()->get_cfiles(str);
    if (!sizeof(filenames))  {
        notify_fail("No such file.\n");
        return 0;
    }

    for(loop = 0; loop < sizeof(filenames); loop++) {

      str = filenames[loop];
       if (file_size(str) < 0 && file_size(str + ".c") < 0) {
          notify_fail("No such file.\n");
          return 0;
       }
/*    err = catch(ob = clone_object(str));
       this_player()->handle_error(err, "clone_object()"); */
       ob = clone_object(str);
       if (ob) {

         err = catch((mov = (int)ob->move(this_player())));
          this_player()->handle_error(err, "move(this_player())");
          if (err || mov) {
             err = catch(ob -> move(environment(this_player())));
             this_player()->handle_error(err, "move(environment())");
          }
          write("Ok.  Object "+file_name(ob)+" cloned and put in "+
             (environment(ob)==this_player() ? "you" :
              (environment(ob)==environment(this_player()) ? "here" : this_player()->desc_object(ob)))+
             ".\n");

         tell_room(environment(this_player()),this_player()->query_cap_name() + " fetches " +
            
((string)ob->query_short()?(string)ob->query_short():"something") +
             " from another dimension.\n",({this_player()}));
       } else {
          tell_object(this_player(),"Failed to clone.\n");
       }
    }
    return 1;
} /* clone() */



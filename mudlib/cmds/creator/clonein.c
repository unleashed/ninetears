/** coded by Raskolnikov July 1996 **/
#include <standard.h>
#include <cmd.h>
inherit CMD_BASE;

void setup(){

    position = 1;
}

static int cmd(string str, object me) {
    object ob;
    string *path, dest, err;
    object *dest2;
    string patron, thane, mudlibber, lord, god;
    int loop, mov;

    patron = "/d/aprior/master"->query_patron(geteuid(me));
    thane = "/secure/thanes"->query_of(me->query_name());
    mudlibber = "/secure/mudlibber"->query_boo(me->query_name());
    lord = "/secure/lords"->query_boo(me->query_name());
    god = "/secure/gods"->query_boo(me->query_name());
    if(!patron && !thane && !mudlibber && !lord && !god) {
	notify_fail("Clonein is for Patrons and higher only.\n");
	return 0;
    }
    if (!str) {
	notify_fail("Usage : clonein file|destination\n");
	return 0;
    }
    sscanf(str, "%s %s", path, dest);
    log_file("CLONEIN", me->query_cap_name()+" tried "
      "to execute clonein "+str+" "+ctime(time())+"\n");
    path = me->get_cfiles(path);
    if(!sizeof(path)) {
	notify_fail("Invalid path.\n");
	return 0;
    }
    if(file_size(path[0]) < 0 && file_size(path[0]+".c") < 0) {
	notify_fail("No such file : "+path[0]+"\n");
	return 0;
    }
    dest = me->expand_nickname(dest);
    dest2 = me->wiz_present(dest, this_player());
    if(!sizeof(dest2)) {
	notify_fail("Invalid destination : "+dest+"\n");
	return 0;
    }
    ob = clone_object(path[0]);
    if (ob) {
	err = catch((mov = (int)ob->move(dest2[0])));
	me->handle_error(err, "move(dest)");
	write("Ok.  Object "+file_name(ob)+" cloned and put in "+
	  ""+dest+".\n");
	tell_room(environment(dest2[0]), this_player()->query_cap_name()+" "
	  "fetches "+(ob->query_short()?ob->query_short():"something")+" "
	  "from another dimension and sticks it in "
	  ""+capitalize(dest)+"\n", ({me}) );
    } else {
	tell_object(me,"Failed to clone.\n");
	return 1;
    }
    log_file("CLONEIN", me->query_cap_name()+" successfully cloned "
      ""+file_name(ob)+" into "+dest+" "+ctime(time())+"\n");
    return 1;
} /* clonein() */

string query_short_help() {
    return "This command clones file into destination.  Path of file "
    "is also valid.  Destination can be any object.\n"
    "For Patrons and higher only.\n\n"
    "Ex: clonein /baseobs/armours/chainmail raskolnikov\n"
    "will clone a chainmail into Raskolnikov.\n";
}

string query_usage() {
    return "clonein file|destination";
}

#include "path.h"
inherit ROOM+"baseroom";

void setup()
{
    my_setup();
    set_short("Realm of the Lizard :  Swamp");

    set_long("Realm of the Lizard : Swamp.\n\n"
      "You are standing on the bank of a poisonous swamp. "
      "The water is dark and malevolent. "
      "A thin film lays on its surface and clings to the bank. "
      "The inhabitants of the swamp have long since perished, leaving only skeletons behind.\n\n");
    set_light(80);
    add_exit("west",ROOMS"swamp08.c","path");
    add_exit("southwest",ROOMS"swamp09.c","path");
    add_exit("south",ROOMS"swamp11.c","path");
}

void init()
{
    ::init();
    add_action("do_search","search");
}

int do_search(string str)
{
    if(str == "hedge")
    {
	write("You search the hedge, and discover an opening in the hedge.\n");
	say(this_player()->query_cap_name()+" searches the hedge.\n");
	add_exit("northeast",ROOMS"swamp12.c","door");
	renew_exits();
	return(1);
    }
    notify_fail("Huh?\n");
    return(0);
}

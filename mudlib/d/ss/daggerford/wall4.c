#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(60);
	set_short("Wall street");
	set_long("You are on Wall street. "+
         "Wall street follows the city walls to the north and south. "+
         "I expect thats why they call it Wall street, because it "+
         "follows the walls. That would be my guess anyway.\n");
	add_exit("north", ROOM+"wall5", "road");
	add_exit("south", ROOM+"tower1", "road");
	set_monster(NUM, "city");
	set_zone("city");
}

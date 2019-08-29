#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(60);
	set_short("Wall street");
	set_long("You are on Wall street. "+
	 "Wall street follows the city-walls to the north and south.\n");
	add_exit("north", ROOM+"wall7", "road");
	add_exit("south", ROOM+"egate", "road");
	set_monster(NUM, "city");
	set_zone("city");
}

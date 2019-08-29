#include "path.h"
#include "/std/outside.c"
inherit CITYROOM;

#define NUM 3

setup()
{
	set_light(60);
	set_short("Wall street");
	set_long("You are on Wall street. "+
	 "Wall street follows the city-walls to the south, and Hill Road follows "+
         "a hill westwards. I wonder why they call it hill road?\n");
	add_exit("west", ROOM+"hill2", "road");
	add_exit("south", ROOM+"wall6", "road");
	set_monster(NUM, "city");
	set_zone("city");
}

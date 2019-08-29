//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Pile of Rocks");
set_light(70);
	set_long("\n   Realm of the Dwarf:  Pile of Rocks\n\n"
	 "     You are standing about half way up a pile of "
		"rocks.  The waterfall coming out of the cave above "
		"has sprayed the rocks causing them to be very "
		"slippery.  You can climb up to the cave from here, "
		"or go down the rocks to the shore.  "
		"\n\n");
	add_item(({"pile of rocks","rock"}),"The rocks are very slippery "
		"and are loose, you need to watch your step.  "
		"\n\n");
	add_item(({"waterfall","spray"}),"The waterfall is sending off "
		"a spray that makes it hard for you to see where you "
		"are going.  "
		"\n\n");
	add_item(({"cave"}),"The waterfall is coming out of the cave "
		"above you.  You can reach the cave by climbing up the "
		"rock pile.  "
		"\n\n");
add_exit("up",ROOM+"dwarf28","path");
add_exit("down",ROOM+"dwarf20","path");
}

//  Dwarven Newbie Area:  Created By Mist   Fall 1994

#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Small Passage");
set_light(80);
	set_long("\n   Realm of the Dwarf:  Small Passage\n\n"
	 "     This is a small passage that runs east and west.  "
		"To the east, you see a large room that is part of "
		"the main cave.  To the west is a beautiful lake and "
		"probably a waterfall, judging from the noise.  A "
		"cool breeze blows past you from the west.  "
		"\n\n");
	add_item(({"lake","beautiful lake"}),"The lake is very large "
		"and beautiful, but judging from the roughness of the "
		"water, it is very dangerous.  "
		"\n\n");
   add_clone(CHAR+"goblin.c",1);
add_exit("east",ROOM+"dwarf18","path");
add_exit("west",ROOM+"dwarf16","path");
}

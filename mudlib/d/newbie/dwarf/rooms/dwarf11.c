//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h";
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Side Passage");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Side Passage\n\n"
	 "     You are inside a side passage just to the east of "
		"the pit.  There is little to see here, but up ahead "
		"to the east, you can see a sharp bend in the passage.  "
		"There is bright light coming from somewhere around "
		"the bend.  "
		"\n\n");
add_exit("east",ROOM+"dwarf12","path");
add_exit("west",ROOM+"dwarf10","path");
   add_clone(CHAR+"cave_rat",1);
   add_clone(CHAR+"spider",1);
   add_clone(CHAR+"drole",random(2));
}

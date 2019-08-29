//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Top of the Rock Pile");
set_light(70);
	set_long("\n   Realm of the Dwarf:  Top of the Rock Pile\n\n"
	 "     This is the top of the pile of rocks that leads up "
		"next to the waterfall.  The rocks are very slippery, "
		"so is would be wise to watch your step.  Going down "
		"will lead to the shore, while going west leads to the "
		"cave with the waterfall coming out of it.  "
		"\n\n");
	add_item(({"pile","pile of rocks","rocks"}),"The pile of rocks "
		"leads down to the bottom of the waterfall.  They are "
		"wet and loose, so you should be very careful going "
		"down there.  "
		"\n\n");
	add_item(({"waterfall","cave"}),"The waterfall comes out of "
		"the cave to the west and thunders to the lake below.  "
		"It is sending off a spray that has drenched the rocks "
		"and shore below.  "
		"\n\n");
	add_item(({"shore"}),"The shore is far below.  You uwould have "
		"to climb down the rocks to get there.  "
		"\n\n");
add_exit("west",ROOM+"dwarf32","path");
add_exit("down",ROOM+"dwarf26","path");
}

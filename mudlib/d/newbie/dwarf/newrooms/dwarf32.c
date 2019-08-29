//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Top of the Waterfall");
set_light(80);
	set_long("\n   Realm of the Dwarf:  Top of the Waterfall\n\n"
	 "     You are standing at the mouth of the cave where the "
		"waterfall comes out and cascades down onto the rocks "
		"below.  Going east leads to the pile of rocks.  Going "
		"south leads into the dark cave along a path that is "
		"right next to the rushing water.  The pathway looks "
		"treacherous because of the loose, wet stones. "
		"\n\n");
	add_item(({"cave","waterfall"}),"The waterfall comes out of the "
		"cave here and thunders onto the rocks below.  The "
		"source of the water might be found if you were to "
		"venture deeper into the cave.  "
		"\n\n");
	add_item(({"pile of rocks","rocks"}),"The pile of rocks leads "
		"downward to the bottom of the waterfall.  "
		"\n\n");
	add_item(({"water","rushing water"}),"The water flows past "
		"you with incredible speed and force.  Since the "
		"water goes over the edge, it might not be wise to "
		"try to enter the water here.  "
		"\n\n");
add_exit("east",ROOM+"dwarf33","path");
add_exit("south",ROOM+"dwarf42","path");
}

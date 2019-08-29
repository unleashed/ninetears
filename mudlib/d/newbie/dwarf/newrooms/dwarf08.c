//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Rocky Shore");
set_light(80);
	set_long("\n   Realm of the Dwarf:  Rocky Shore\n\n"
	 "     The beach here has less sand than to the south.  The "
		"only sand that can be seen is between the large rocks "
		"that line the shore here.  The whirlpool can be seen "
		"better from this view atop the rocks.  You had no "
		"idea that it was so huge and powerful.  The speed of "
		"water as it churns around and around is frightening "
		"as well as impressive.  A fall into the water would mean "
		"almost certain death.  The shoreline continues northwest "
		"along the northern shore and to the south towards the  "
		"waterfall.  "
		"\n\n");
	add_item(({"beach","sand","rocks","shore"}),"The beach here is hard "
		"to find between the large rocks.  There is a little "
		"sand here, but not as much as you would find to the "
		"south.  "
		"\n\n");
	add_item("waterfall","The waterfall is sending off a spray "
		"that blocks out the view of the southern end of the "
		"cave.\n\n");
	add_item(({"whirlpool","water"}),"The whirlpool is spinning "
		"very fast and looks to be mighty powerful.  The water "
		"is pulled down into what must be a cavern underneath "
		"the surface of the water.  "
		"\n\n");
add_exit("south",ROOM+"dwarf13","path");
add_exit("northwest",ROOM+"dwarf06","path");
}

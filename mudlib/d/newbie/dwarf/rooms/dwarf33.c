//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Path Along the River");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Path along the River\n\n"
	 "     This is a path inside the cave that runs right next "
		"to the river.  The rocks here are loose and wet.  "
		"Better watch your step, a fall here would dump you "
		"into the swift moving river and send you over the "
		"waterfall.  To the north you can see the mouth of the "
		"cave.  Far to the south you can see light, possibly "
		"from a fire.  "
		"\n\n");
	add_item(({"path","river"}),"The path runs right next to the "
		"swiftly moving river.  The loose rocks in the path "
		"cause this path to be very dangerous.  A fall here "
		"would put you in the river and send you over the falls.  "
		"\n\n");
	add_item(({"cave"}),"The cave is just wide enough for you to "
		"pass through next to the river.  "
		"\n\n");
	add_item("rock","The rocks are loose and slippery.  Better "
		"watch your step.\n\n");
add_exit("south",ROOM+"dwarf38","path");
add_exit("north",ROOM+"dwarf27","path");
}

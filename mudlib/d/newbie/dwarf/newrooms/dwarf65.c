//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Top of Rapids");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Top of Rapids\n\n"
            "   You are standing at the top of a steep downward "
            "slope in the cave.  The underground river here has "
            "gained quite a bit of speed and is tumbling down the "
            "slope and crashing onto the rocks below.  It would be "
            "quite impossible to get down to the bottom safely if "
            "it were not for the small passage that runs along the "
            "side of the river.  "
		"\n\n");
add_exit("down",ROOM+"dwarf67","path");
add_exit("west",ROOM+"dwarf64","path");
}

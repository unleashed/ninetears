//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Tangle of Roots");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Tangle of Roots\n\n"
            "   The thousands of roots extending down into the water "
            "make the cave here almost impossible to work your way "
            "through.  The roots beneath the water twist and work their "
            "way around your legs causing you to stager and trip as you "
            "try to get through.  The tangle of roots seems less dense "
            "to the west and much thicker to the south.  "
		"\n\n");
add_exit("south",ROOM+"dwarf73","path");
add_exit("west",ROOM+"dwarf68","path");
}

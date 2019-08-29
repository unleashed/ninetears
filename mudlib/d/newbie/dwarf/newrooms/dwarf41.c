//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Flooded Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Flooded Cave\n\n"
            "   The cave narrows here, barely allowing you to pass "
            "through.  The current here is very fast and the knee-deep "
            "water numbs your legs as it trys to pull you to the south.  "
            "You can feel the creatures within the water as they brush "
            "by and nip at your legs.  The flooded cave continues both "
           "north, towards the falls and south into deeper water.  "
		"\n\n");
add_exit("north",ROOM+"dwarf31","path");
add_exit("south",ROOM+"dwarf50","path");
}

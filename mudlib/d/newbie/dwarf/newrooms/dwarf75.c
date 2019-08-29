//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Dead End");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Dead End\n\n"
            "   The cave ends here at a large wall to the east with "
            "a hole just large enough to allow the water to escape.  "
            "With the water as high as it is, the hole in the eastern " 
            "is filled, almost to the top, with water.  Only a small "
            "gap of air can be seen above the water, however this "
            "gap is filled with sharp looking protrusions from the "
            "rocks above.  The only way out is the way you came in, "
            "back to the west.  "
		"\n\n");
add_exit("west",ROOM+"dwarf74","path");
}

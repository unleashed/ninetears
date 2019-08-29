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
            "   The tangle of roots had trapped the sand and sediment "
            "that the river has pushed down here.  This sediment, along "
            "with the roots has formed a small dam that blocks off a "
            "portion of the river here.  You can climb up onto this dam "
            "to the southeast and leave the icy cold water.  The tangle "
            "of roots continues to the north.  "
		"\n\n");
add_exit("north",ROOM+"dwarf69","path");
add_exit("southeast",ROOM+"dwarf79","path");
}

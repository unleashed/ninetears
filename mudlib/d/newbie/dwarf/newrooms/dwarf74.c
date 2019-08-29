//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Cave\n\n"
            "  The thick tangle of roots extends from the southwest "
            "and makes the footing in this flooded cavern somewhat "
            "treacherous.  The cold water flows through here from "
            "underneath the thick tangle of roots to the southeast "
            "and moves eastward as the cave narrows.  "
		"\n\n");
add_exit("east",ROOM+"dwarf75","path");
add_exit("southwest",ROOM+"dwarf79","path");
}

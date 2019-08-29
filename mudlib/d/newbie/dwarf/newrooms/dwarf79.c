//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Dam");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Dam\n\n"
            "  You climb out of the cold water onto the soggy, wet "
            "sand.  The sand and silt here is held in place by the "
            "thick tangle of roots.  As you move along on your hands and "
            "knees, you notice a path through the roots leading away "
            "from the river to the west.  This path is high enough to "
            "allow you to stand with ease.  Going northwest leads back "
            "into the river, through more thick roots.  Moving "
            "northeast leads into the river, away from the tangle.  "
		"\n\n");
add_exit("west",ROOM+"dwarf78","path");
add_exit("northwest",ROOM+"dwarf73","path");
add_exit("northeast",ROOM+"dwarf74","path");
}

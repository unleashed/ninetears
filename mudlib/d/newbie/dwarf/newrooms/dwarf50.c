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
            "   The water comes to your waist here and you are having "
            "trouble standing on the slippery cave floor.  The current "
            "coming from the north pulls you to the southeast and "
            "makes movement towards the north almost impossible.  "
            "The passage north leads toward the sound of a waterfall "
            "and into shallow water.  The passage southeast looks to be "
            "very deep and dangerous.  "
		"\n\n");
add_exit("north",ROOM+"dwarf41","path");
add_exit("southeast",ROOM+"dwarf58","path");
}

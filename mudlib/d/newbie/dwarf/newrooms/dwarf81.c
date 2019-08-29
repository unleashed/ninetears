//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Tunneled out Cavern");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Tunneled out Cavern\n\n"
            "   The carved out tunnel bends sharply here going north "
            "and east.  From the north you are able to hear the sounds "
            "and east.  The walls of the cave here are somewhat rougher "
            "than those to the north.  The marks from the picks are "
            "deeper and there are many small holes that go deep into "
            "the wall.  The ceiling is also lower, forcing you to "
            "stoop down, very low to the ground.  From the tunnel to "
            "the north, you can hear the sounds of the river.  The "
            "tunnel east seems to open up into a large room.  "
		"\n\n");
add_exit("north",ROOM+"dwarf78","path");
add_exit("east",ROOM+"dwarf82","path");
}

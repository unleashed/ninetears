//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Large pool");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Large pool\n\n"
            "   The water pouring down through the rapids above, has "
            "worked to fill a large pool in the floor here.  The force "
            "of the rushing water has carved out a very large (and likely "
            "very deep) hole in the cave floor.  The only way around it "
            "is a small pathway that runs along the cave wall.  This "
            "path runs upward along the rapids, east into the river, and "
            "into a small hole in the southern wall.  "
		"\n\n");
add_exit("up",ROOM+"dwarf67","path");
add_exit("south",ROOM+"dwarf76","path");
add_exit("east",ROOM+"dwarf71","path");
}

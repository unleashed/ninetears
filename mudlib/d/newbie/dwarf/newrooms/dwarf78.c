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
            "  Someone has obviouislsly carved out a very large tunnel in "
            "the cave wall.  This tunnel is high enough that you only "
            "need to stoop down slightly to avoid scratching your head "
            "against the ceiling.  The floor, walls, and ceiling are "
            "rather smooth, however you can see the marks left by "
            "the picks or other tools that were used to form this "
            "tunnel.  This tunnel continues to the south and the main "
            "cave is to the east.  "
		"\n\n");
add_exit("south",ROOM+"dwarf81","path");
add_exit("east",ROOM+"dwarf79","path");
}

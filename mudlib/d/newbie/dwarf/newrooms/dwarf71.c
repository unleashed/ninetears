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
            "   The roots sticking out from the roof of the cave here "
            "indicate that this part of the cave is very close to the "
            "surface.  Thick roots snake downward into the water and "
            "smaller roots reach out in all directions like a spider's "
            "web.  This tangle of roots almost completely blocks the "
            "curving passage to the northeast.  The way west leads out "
            "of the water near a large waterfall.  "
		"\n\n");
add_exit("west",ROOM+"dwarf70","path");
add_exit("northeast",ROOM+"dwarf68","path");
}

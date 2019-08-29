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
            "   Your body is almost completely submerged in the icy "
            "cool water as you slowly work your way through the flooded "
            "cave.  The cave is fairly wide here and the water is not"
            "very deep at all, however the low ceiling forces you to "
            "lower your body into the water to keep from slamming "
            "your head into the rocks above.  The cave walls here are "
            "smooth from many years of water running through here and "
            "the floor feels just as smooth.  The floor is also slick "
            "for some reason and it is difficult to keep your footing.  "
            "The cave splits here with a small room off to the "
            "southwest, where water is pooled up.  The underground "
            "river continues to the north and east.  "
		"\n\n");
add_exit("north",ROOM+"dwarf58","path");
add_exit("east",ROOM+"dwarf64","path");
add_exit("southwest",ROOM+"dwarf66","path");
}

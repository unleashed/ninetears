//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Deep Pool");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Deep Pool\n\n"
            "   You have come to a dead end in the cave.  The water from "
            "the river has pooled up here and is so deep that you are "
            "unable to touch the bottom.  The walls here are perfectly "
            "smooth and offer you nothing to hold on to.  The water "
            "is quite clear here and you can see several large shapes "
            "hovering just below the surface.  "
		"\n\n");
add_exit("northeast",ROOM+"dwarf63","path");
}

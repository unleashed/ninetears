//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Rapids");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Rapids\n\n"
            "   The cave here is tilted wildly and the flowing river has "
            "changed into a set of roaring rapids.  The water is slamming "
            "into jagged rocks that are scattered all across the width "
            "of the river, causing foam and spray to be tossed all around "
            "the cave.  You are just barely able to work your way around "
            "the rapids on a small ledge that is running along the cave "
            "wall.  This small and dangerous pathway runs upward towards "
            "the upper part of the rapids and downward to the bottom.  "

		"\n\n");
add_exit("up",ROOM+"dwarf65","path");
add_exit("down",ROOM+"dwarf70","path");
}

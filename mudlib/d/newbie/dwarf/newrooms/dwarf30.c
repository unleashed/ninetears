//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Narrow Corner");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Narrow Corner\n\n"
            "   The tight cave comes to a very sharp corner here and is "
            "almost impossible to wiggle and squirm your way "
            "through.  From here, you can hear the distinct sound "
            "of water to the southwest, and some very unusual sounds "
            "that you cannot recognize to the south.  "
            "A faint glimmer of light can be seen shining off of "
            "the walls.  It is coming from the south, where the "
            "cave opens up a bit, although you are unable to determine "
            "the source.  "
		"\n\n");
add_exit("south",ROOM+"dwarf39","path");
add_exit("southeast",ROOM+"dwarf40","path");
}

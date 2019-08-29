//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Cave\n\n"
            "   You are standing in a wildly tilted passage through "
            "the cavern.  You are able to stand upright here and the "
            "passage has much more room than the tight corner to the north "
            "which is almost impassible.  There is a large room to the "
            "southeast that is brightly lit with wild shadows coming "
            "out that must be from some very large creature.  "
		"\n\n");
add_exit("north",ROOM+"dwarf30","path");
add_exit("southeast",ROOM+"dwarf49","path");
}

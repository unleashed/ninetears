//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Cave\n\n"
            "   The tangle of twisted roots extends from the ceiling "
            "of the cave all the way down to the live giving water that "
            "you are trudging through.  The ceiling of the cave is far "
            "above your head, but even if it were lower, you would "
            "not be able to penetrate the thick tangle of roots.  As "
            "you move about, you are startled by something rubbing up "
            "against your foot, but you calm down as you realize that "
            "it is just a large root concealed by the deep murky water.  "
            "The passage leads further into the tangle of roots to the "
            "east.  Going southwest will lead you out of the roots, into "
            "a wide open cave.  "
		"\n\n");
add_exit("east",ROOM+"dwarf69","path");
add_exit("southwest",ROOM+"dwarf71","path");
}

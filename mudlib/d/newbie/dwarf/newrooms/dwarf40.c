//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Narrow Passageway");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Narrow Passageway\n\n"
            "   You are barely able to squeeze your body through "
            "this very narrow passageway in the cave.  This passage "
            "is actually nothing more than a crack that runs upward "
            "at a wild angle causing you to bend your body into "
            "an uncomfortable position in order to move through.  "
            "To the northeast, the cave opens up into a much larger, "
            "flooded cave.  The cave tightens up a bit more to the "
            "northwest and may be difficult to pass through.  "
		"\n\n");
   add_item(({"passage","passageway","cave","crack"}),"\n   This small "
              "passageway tilts wildly and makes movement through "
              "here extremely difficult and uncomfortable.\n\n");
add_exit("northeast",ROOM+"dwarf31","path");
add_exit("northwest",ROOM+"dwarf30","path");
}

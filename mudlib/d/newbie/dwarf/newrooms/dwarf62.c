//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Small ledge");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Small ledge\n\n"
            "   You are standing on a small ledge just above a fast "
            "moving underground stream.  The ledge sits several feet "
            "above the surface of the water here.  The darkness in the "
            "cave make it impossible to tell just how deep the water "
            "below actually is, but you are able to tell that the water "
            "is teeming with life.  You can make out the forms of small "
            "fish, snakes, and other creatures that you are unable to "
            "recognize.  There is a narrow passage to the west that "
            "appears to have been carved out by hand.  "
		"\n\n");
add_exit("west",ROOM+"dwarf61","path");
add_exit("northeast",ROOM+"dwarf58","path");
}

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
            "   Here the cave opens up into a very large room.  The walls "
            "of the room extend upward to a very high ceiling.  From "
            "here you are able to see a very large passage leading northward "
            "into the blackness far above you.  The walls and floor "
            "are scarred with burn marks and covered with black soot.  "
            "There are two large stones standing upright on the near side "
            "of the room.  Oddly enough, they are only blackened on "
            "one side, as the side closest to you is clean and "
            "smooth.  "
		"\n\n");
add_exit("northwest",ROOM+"dwarf39","path");
}

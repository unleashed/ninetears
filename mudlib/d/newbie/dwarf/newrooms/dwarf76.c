//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Small Passage");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Small Passage\n\n"
		"\n\n");
add_exit("north",ROOM+"dwarf70","path");
add_exit("east",ROOM+"dwarf77","path");
add_exit("southwest",ROOM+"dwarf80","path");
}

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
		"\n\n");
add_exit("north",ROOM+"dwarfXX","path");
add_exit("south",ROOM+"dwarfXX","path");
add_exit("east",ROOM+"dwarfXX","path");
add_exit("west",ROOM+"dwarfXX","path");
add_exit("northeast",ROOM+"dwarfXX","path");
add_exit("northwest",ROOM+"dwarfXX","path");
add_exit("southwest",ROOM+"dwarfXX","path");
add_exit("southeast",ROOM+"dwarfXX","path");
}

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
		"\n\n");
add_exit("north",ROOM+"smithy","path");
add_exit("south",ROOM+"dwarf56","path");
add_exit("east",ROOM+"dwarf48","path");
add_exit("west",ROOM+"dwarf46","path");
}

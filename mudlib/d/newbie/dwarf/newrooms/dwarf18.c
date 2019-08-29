//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Long Cave");
set_zone("CAVE");
set_light(60);

	set_long("\n   Realm of the Dwarf:  Long Cave\n\n"
	 "     Here the cave opens up into a large room.  The sound "
		"of the rushing water comes at you from all directions "
		"making it hard for you to locate the source.  A cool "
		"breeze blows in from the west.  You shiver as the "
		"cold air moves across your damp clothes.  The tunnel "
		"continues to the north and south and a small passage "
		"leads downward to the west. "
		"\n\n");
add_exit("south",ROOM+"dwarf22","path");
add_exit("north",ROOM+"dwarf14","path");
add_exit("west",ROOM+"dwarf17","path");
add_clone(CHAR+"cave_rat.c",2);
}

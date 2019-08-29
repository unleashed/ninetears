//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h";
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Sharp Bend");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Sharp Bend\n\n"
	 "     This is a sharp bend in the passage way.  One tunnel "
		"goes off to the west, while the other goes south into "
		"a large room with bright light coming out of it.  There "
		"is a strange clanging sound coming from the south.  "
		"\n\n");
add_exit("south",ROOM+"dwarf15","path");
add_exit("west",ROOM+"dwarf11","path");
add_clone(CHAR+"thief.c",1);
}

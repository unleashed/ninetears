//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Bend in Tunnel");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Bend in Tunnel\n\n"
	 "     This is a bend in the tunnel.  The passage to the "
		"south leads into a dead end, while the narrow passage "
		"to the west goes back to the main part of the cave.  "
		"You can hear the sounds of shouting and laughing "
		"from the south.  "
		"\n\n");
add_exit("south",ROOM+"dwarf42","path");
add_clone(CHAR+"spider",1);
add_clone(CHAR+"cave_rat.c",1);
add_exit("west",ROOM+"dwarf35","path");
}

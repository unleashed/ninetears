//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h";
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Sandy Beach");
set_light(80);
	set_long("\n   Realm of the Dwarf:  Sandy Beach\n\n"
	 "     You are standing on a sandy beach next to the edge "
		"of the lake.  The waters of the lake here are in a "
		"turmoil here, because of the large whirlpool.  You "
		"can't tell for sure what the cause of the whirlpool "
		"is, but it must be due to an underwater cave that "
		"serves as an outlet for the lake water.  To the "
		"north is more of the sandy shore.  It might go around "
		"the lake.  Going south leads back toward the waterfall "
		"along the sandy shore.  "
		"\n\n");
	add_item(({"beach","shore","sandy shore"}),"The beach here "
		"runs along the water's edge.  Your feet sink somewhat "
		"into the white sand here as you move along.  "
		"\n\n");
	add_item(({"lake","water","whirlpool"}),"The waters of the "
		"lake are in a turmoil here because of the force of tehe "
		"whirlpool.  The whirlpool is pulling the water down "
		"into a tunnel under the lake.  "
		"\n\n");
	add_item(({"waterfall","falls"}),"The waterfall thunders down "
		"onto the rocks far to the south.  The spray coming "
		"from it obscures your view of the southern wall of "  
		"the cave.  "
		"\n\n");
add_exit("south",ROOM+"dwarf16","path");
add_exit("north",ROOM+"dwarf08","path");
}

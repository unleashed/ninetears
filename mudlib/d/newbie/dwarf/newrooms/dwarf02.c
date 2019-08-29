//  Dwarven Newbie Area ---- Created by Mist ---- Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Bright Room");
set_light(90);
	set_long("\n   Realm of the Dwarf:  Bright Room\n\n"
		"     This is a small room that sits very close to the "
		"ledge.  The ledge overlooks the huge pit below.  "
		"This room looks as if it has an exit that leads to the "
		"outside of the cave.  To the north there is a ledge "
		"that is outside.  You can feel the fresh air that "
		"is coming in through the hole.  It is very refreshing.  "
		"You may also travel west, back onto the ledge overlooking "
		"the pit.  "
		"\n\n");
	add_item(({"ledge","pit","overlook"}),"The ledge overlooks "
		"the great pit.  You are unable to see the pit from here "
		"\n\n");
	add_item(({"outside","east","hole"}),"The hole leads to the "

		"outside.  You can feel the cool, fresh air pouring "
		"through the hole.  It feels very refreshing.  "
		"\n\n");
add_exit("out",ROOM+"dwarf03","path");
add_exit("west",ROOM+"dwarf01","path");
}

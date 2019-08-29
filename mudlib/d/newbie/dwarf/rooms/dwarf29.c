//  Dwarven Newbie Area:  Created By Mist   Fall 1994

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Cave\n\n"
	 "     Here the cave bends south and northwest.  You can "
		"hear the faint sounds of rushing water to the "
		"northwest.  There is a small room to the northeast "
		"that looks like it has a large altar in it.  "
		"\n\n");
	add_item("path","The room to the northeast looks like a small "
		"temple.  Might be a good place to get raised if you "
		"are dead.  "
		"\n\n");
	add_item("altar","There is a large altar in the room to the "
		"northeast.  Looks as if that might be a temple.  "
		"\n\n");
add_clone(CHAR + "cave_rat.c",2);
add_exit("south",ROOM+"dwarf34","path");
add_exit("northwest",ROOM+"dwarf24","path");
add_exit("northeast",ROOM+"raiserm25","path");
}

//  Dwarven Newbie Area:  Created By Mist   Fall 1994

#include "path.h"
inherit ROOM+"baseroom.c";

void setup()
{
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Cave\n\n"
	 "     Here the cave bends north and southeast.  To the "
		"north, the sound of rushing water greets your ears.  "
		"The dark tunnel continues to the southeast and there "
		"is a small hole leading northeast.  "
		"\n\n");
	add_item(({"hole","small hole"}),"This is a small hole in the "
		"wall.  It leads to the northeast and looks like is "
		"twists and turns for quite a distance.  "
		"\n\n");
   add_clone(CHAR+"cave_rat.c",2);
add_exit("north",ROOM+"dwarf21","path");
add_exit("northeast",ROOM+"dwarf22","path");
add_exit("southeast",ROOM+"dwarf29","path");
}

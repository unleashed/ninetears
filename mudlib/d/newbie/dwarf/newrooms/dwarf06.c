//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Northern Shore");
set_light(80);

	set_long("\n   Realm of the Dwarf:  Northern Shore\n\n"
	 "     You are standing on the rocky, northern shore of "
		"the underground lake.  The lake lies to the south.  "
		"You can clearly see and hear the incredible waterfall "
		"that is located on the opposite side of the lake. "
		"The whirlpool can also be seen just south of this shore.  "
		"To the west the path leads away from the lake, through "
		"some large rocks.  To a southeast the path goes "
		"around to the rest of the shoreline.  "
		"\n\n");
	add_item(({"rock","shore"}),"The shore here is composed mostly "
		"of rocks.  They are smooth, but luckily they are dry.  "
		"\n\n");
	add_item(({"lake","whirlpool"}),"This end of the lake is "
		"dominated by the mighty whirlpool.  There is not "
		"much else to see.  "
		"\n\n");

	add_item(({"waterfall","spray"}),"The waterfall can be seen crashing "
		"down in the distance.  It is sending off a spray that "
		"obscures the entire southern wall.  "
		"\n\n");
    add_clone(CHAR+"goblin.c",1);
   add_clone(CHAR+"drole",2);
add_exit("west",ROOM+"dwarf05","path");
add_exit("southeast",ROOM+"dwarf08","path");
}

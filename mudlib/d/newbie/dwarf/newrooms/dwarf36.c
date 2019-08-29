//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Narrow Path");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Narrow Path\n\n"
	 "     This is a small path that leads to the Blind Bat "
		"Tavern to the north, and goes into the center of "
		"town to the south.  The loud cheers and singing "
		"coming from the tavern indicate to you that "
		"everyone in there is having a very good time.  "
		"\n\n");
	add_item("tavern","This "
		"is the Blind Bat Tavern.  From the sounds inside, it "
		"would seem that they are having a good time in there.  "
		"You might want to go in and see what is going on.  "
		"\n\n");
add_exit("south",ROOM+"dwarf46","path");
add_exit("north",ROOM+"tavern","path");
}

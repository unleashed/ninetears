//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Sharp Bend");
set_zone("CAVE");
set_light(15);
	set_long("\n   Realm of the Dwarf:  Sharp Bend\n\n"
	 "     As soon as you enter this end of the passage, you "
		"realize that there are two exits.  This is not a "
		"dead end after all.  There is a small passage to the "
		"north and a larger one to the northeast.  You are "
		"somewhat surprised that the passage to the northeast "
		"seems to lead into a small village.  That must be "
		"where all of that noise is coming from.  "
		"\n\n");
	add_sound("noise","The noise is much louder here and is "
		"coming from the northeast.  From the sound of it "
		"there must be a tavern in the small village.  "
		"\n\n");
	add_item("village","The village is visible to the northeast.  "
		"You can just make out a couple of buildings from here. "
		"\n\n");
add_item("building","The buildings are small and old.  One of "
		"them must be a tavern and another looks like a smithy. "
		"\n\n");
add_exit("north",ROOM+"dwarf45","path");
add_exit("northeast",ROOM+"dwarf46","path");
add_clone(CHAR+"spider",1);
add_clone(CHAR+"cave_rat.c",1);
}

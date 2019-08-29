//  Dwarven Newbie Area:  Created By Mist   Fall 1994
#include "path.h"
inherit ROOM+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Little Village");
set_light(60);
	set_long("\n   Realm of the Dwarf:  Little Village\n\n"
	 "     This is the town center for the clan Flintfire.  "
		"There are people milling about doing their daily "
		"chores.  They do not seem to be bothered by your "
		"presence here, in fact, you feel somewhat welcome.  "
		"To the northeast, you can see a small shop with a "
		"large wooden sign hanging over the door.  Far to the "
		"north you see what looks like a tavern.  The sounds "
		"of singing and mugs crashing together in a merry "
		"toast greet your ears from there.  There is another "
		"smaller building to the northwest with something "
		"written on the door.  There is a dark and narrow "
		"passage to the southwest that looks like a dead end. "
		"\n\n");
	add_item("door","The door has writing scrawled upon it.  It reads:\n"
		"Zundrin's Equipment Shop\n\n");
	add_item(({"sign","wooden sign","shop"}),"\n\n"

		"  #===========================================#\n"
		"  #                                           #\n"
		"  #            Darklor's Smithy               #\n"
		"  #                                           #\n"
		"  #===========================================#\n\n");
	add_item("building","This building looks like a small shop.  "
		"It may be a place where you can buy and sell items.  "
		"\n\n");
	add_item("people","The people are moving about, taking care of "
		"whaterver business they might have in the village.  "
		"Their smiles and nods make you feel welcome at once.  "
		"\n\n");
add_exit("north",ROOM+"dwarf36","path");
add_exit("southwest",ROOM+"dwarf55","path");
add_exit("east",ROOM+"dwarf47.c","path");
add_exit("northwest",ROOM+"shop.c","path");
add_clone(CHAR+"thief.c",1);
}

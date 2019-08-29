#include "path.h"
inherit ROOM+"baseroom";
#include "restock.c"

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	 "     Once again you find yourself deeper into the swamp. There "
	 "is another one of those strange looking vines "
	 "here but this one is about three times the size "
	 "of any of the ones you've seen so far. This one "
	 "looks hungry. Dont get too close. \n\n");
add_property("no_undead",1);
add_item("trail", "The trail you were following disappears into "
	 "the swamp.\n\n");
add_exit("north",SWAMP +"lizard03","room");
add_exit("west",SWAMP +"lizard06","room");
add_clone(MONSTER+"vine.c",1);

}

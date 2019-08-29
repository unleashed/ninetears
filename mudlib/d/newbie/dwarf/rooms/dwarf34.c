//  Dwarven Newbie Area:  Created By Mist   Fall 1994
  inherit "/std/room.c";
#include "path.h"

  void setup ()  {
   add_property("no_undead",1);
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);
	set_long("\n   Realm of the Dwarf:  Cave\n\n"
	 "     The cave has opened up and you are now able to "
		"stand upright.  The floor is slippery from all of "
		"this water that is falling from above.  You have to be "
		"careful not to fall down.  The cave continues to the "
		"north and south.  There is a small passageway leading "
		"off to the east.  You almost miss a low passage to "
		"the southwest.  "
		"\n\n");
	add_item("floor","This is the cave floor.  It looks very "
		"slippery due to all of the water.  You might ought "
		"to watch your step.  "
		"\n\n");
	add_item("water","The water falls down onto the floor from "
		"somewhere above.  It is causing the floor to be "
		"very slippery.  "
		"\n\n");
	add_item("cave","This is a cold, damp cave with very little "
		"light.  Every step you make echos throughout it and "
		"sounds as if someone else is in here.  "
		"\n\n");
	add_feel("floor","The floor is slippery from the water that "
		"covers it.  The hard rock that makes up the floor "
		"is not level, making the footing trecharous.  "
		"\n\n");
add_exit("south",ROOM+"dwarf41","path");
add_exit("north",ROOM+"dwarf29","path");
add_exit("east",ROOM+"dwarf35","path");
add_exit("southwest",ROOM+"dwarf40","path");

add_clone(CHAR+"cave_rat.c",1);
  add_clone(CHAR+"drole.c",1);

}

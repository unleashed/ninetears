//  Dwarven Newbie Area:  Created By Mist   Fall 1994

#include "path.h"
 inherit "/std/room.c";

 void setup ()  {
set_short("Realm of the Dwarf:  Cave");
set_light(40);
   add_property("no_undead",1);
	set_long("\n   Realm of the Dwarf:  Cave\n\n"
	 "     This is a cold, damp cave with a very low ceiling.  "
		"You must squat low to move through this part of the "
		"cave.  The only sounds you hear, other than your own "
		"footsteps, are the droplets of water falling from "
		"the ceiling onto the floor.  To the north, the cave "
		"seems to open up a bit.  To the south, there seems "
		"to be a large cave-in."
		"\n\n");
	add_item(({"ceiling"}),"The ceiling here is very low.  You "
		"must be careful not to hit your head.  There are "
		"droplets of water falling from the ceiling onto "
		"the floor."
		"\n\n");
	add_item(({"floor"}),"The floor is wet.  Must be from all "
		"that water that has been falling from the ceiling.  "
		"\n\n");
	add_item(({"droplets","water"}),"The droplets of water are "
		"falling down onto the floor and on you.  They are "
		"cold and send shivers up and down your spine.  "
		"\n\n");
	add_item("cave","This is a cold and dark cave.  The floor is "
		"covered with water that has fallen from the ceiling.  "
		"\n\n");
	add_sound(({"water","droplets"}),"You can hear the droplets "
		"of water falling from the ceiling onto the floor.  "
		"This sound is almost unnerving in the silence of "
		"the cavern.  "
		"\n\n");
	add_feel(({"floor","cave","ceiling"}),"The floor and ceiling "
		"of the cave are wet and slimy from the water that "
		"is falling from the ceiling.  "
		"\n\n");
  add_clone(CHAR+"spider.c",1);
add_exit("south",ROOM+"dwarf43","path");
add_exit("north",ROOM+"dwarf34","path");
}

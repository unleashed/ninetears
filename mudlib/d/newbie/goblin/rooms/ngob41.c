// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  River");
   set_light(20);
   set_zone("newbie_river");
set_long("\nRealm of the Goblin:  River\n\n"
	 "     This part of the river comes to a end here. You can see "
 "a dry cave to the northeast. It looks different from the rest of "
 "the cavern you have been wading through. Perhaps you should turn "
"around and go back.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
"with moss and fungus.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("cave","This cave from what you can see from this distance "
 "looks like it has been recently dug. You think you see movement "
 "in the cave.\n");
add_item("river","This river doesn't look to deep as far as you "
"can tell, maybe about two feet deep. You see some blind fish swimming "
"in it occassionally.\n");
add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
"they look quite tasty.\n");

// Items....

add_exit("northeast", ROOM+"ngob42.c","path");
add_exit("south", ROOM+"ngob40.c","path");
// Exits....
} /*setup() */


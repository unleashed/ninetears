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
	 "     The river is not flowing at all here and it is unusually "
  "quiet. You have a wierd feeling that you shouldn't go any further "
 "to the north.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
"with moss and fungus.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("river","This river doesn't look to deep as far as you "
"can tell, maybe about two feet deep. You see some blind fish swimming "
"in it occassionally.\n");
add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
"they look quite tasty.\n");
add_item("north","You see more river to the north.");

// Items....

add_exit("north", ROOM+"ngob45.c","path");
add_exit("southwest", ROOM+"ngob39.c","path");
// Exits....
} /*setup() */


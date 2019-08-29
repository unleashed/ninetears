// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Cave");
   set_light(20);
   set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Cave\n\n"
	 "     The caves gets a little larger here, you can continue south "
    "or north. You don't see much here except bare rock walls.\n\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("north wall","This wall has a section in it where "
  "the rock has been dug out. It appears to have been the start "
  "of a tunnel extension, but the work must have been abandoned.\n");

// Items....
add_exit("south",ROOM+"cave3.c","path");
add_exit("north", ROOM+"cave1.c","path");

// Exits....
} /*setup() */


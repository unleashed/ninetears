
#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
   set_short("Realm of the Goblin:  Tunnels");
   set_light(20);
   set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Tunnels\n\n"
	 "     You stand outside of a really large gate. "
    "It is locked and no matter how much you pound on it, it "
    "will not open. The tunnel you stand in is bare and damp. "
   "It continues south to who knows where.\n\n");
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
add_exit("south",ROOM+"cave2.c","path");

// Exits....
} /*setup() */


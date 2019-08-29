// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h"

inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnel");
set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
	 "     You have come to an intersection in the tunnel you hear"
" water lapping to the west, to the north you can just make out some ruins of some kind."
" You are quite tired from all your traveling the ruins look like"
" a good place to get some rest.\n\n");
add_property("no_undead",1);
add_item(({"roof"}),
"There is water dripping fom the stone above your head as you look up"
" some dirty water falls into your eyes blinding you for a moment.\n");
add_item(({"floor"}),
"The floor is compleatly smooth stone except for the occasional"
" pile of goblin excrement.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("west",ROOM+"ngob36.c","path");
add_exit("north",ROOM+"ngob37.c","path");
add_exit("south",ROOM+"ngob34.c","path");
// Exits...

add_clone(CHAR+"drole.c",2);
} /* setup() */

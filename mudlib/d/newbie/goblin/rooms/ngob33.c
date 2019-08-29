// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h"

inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnel");
set_long("Realm of the Goblin:  Gloomy Tunnels\n\n"
	 "     Bare rock is all around you except to the southwest and north. "
"To the southwest you see what appears to be a bridge over a hole of some kind. "
"To the north the tunnel appears to be getting wider and looks "
"like it has been traveled in recently. Although no footprints go "
"any farther to the southwest must mean something.\n\n");
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
  add_item("bridge","You see a bridge of some sort, can't tell much "
          "about it from this distance.\n");
  add_item("hole","Some kind of hole or crack in the ground, "
       "can't see much from this distance.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("north",ROOM+"ngob34.c","path");
add_exit("southwest",ROOM+"ngob49.c","path");
// Exits...

add_clone(CHAR+"drole.c",1);
} /* setup() */

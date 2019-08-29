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
	 "     You are in a dark, damp passage. The walls here are covered "
"with moss and fungus. The tunnel here gets very narrow. "
"The walls here are very rough like this tunnel was just"
" made recently."
" This tunnel is probably not finished since all the dwarf slaves"
" from the war died years ago. Goblins need not bother with doing work that others can do."
" To the south you see a less travelled tunnel. You hear lots of noise to "
" the north. To the west you can just make out a statue in the distance.\n\n");
add_property("no_undead",1);
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
add_item("statue","The statue is still too far to see clearly.\n");

// Items...

add_exit("southeast","/d/newbie/goblin/rooms/ngob32.c","path");
add_exit("north","/d/newbie/goblin/rooms/ngob4.c","path");
// Exits...

add_clone(CHAR+"drole.c",1);

} /* setup() */

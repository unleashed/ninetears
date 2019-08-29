// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";

void setup() {
// Descriptions...
   set_short("Underground River");
   set_light(20);
   set_zone("newbie_river");
set_long("This passage of the river does not have any current. "
  "It is a little shallower here, only about a foot and a half feet deep. "
  "You can go north or into the lake to the south.\n");
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

// Items....

add_exit("north", ROOM+"ngob40.c","path");
add_exit("south", ROOM+"ngob30.c","path");
// Exits....
} /*setup() */


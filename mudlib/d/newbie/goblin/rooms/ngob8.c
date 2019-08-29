// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h"
inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Caverns");
   set_light(20);
   set_zone("goblin_newbie");
set_long("\nRealm of the Goblin:  Gloomy Caverns\n\n"
	 "     You are in a dark, damp passage. The walls here are covered "
"with moss and fungus. There is a sign here in this large cave"
" pointing to the north to a shop of some kind. The floor here is very slick from water"
" dripping from the top of the cavern and down the walls."
" There is a small tunnel leading off to the southwest."
" There is a large passage leading to the southeast toward"
" The monument of chip-tooth the dwarf slayer.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
add_item(({"floor"}),
"The floor here is so slick you almost lose your footing while"
" bending over to look at it. The water on the rock here is very"
" cold against your soft young feet.\n");
add_item(({"sign"}),
"BUY SELL We have it all.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("southwest","/d/newbie/goblin/rooms/ngob10.c","path");
add_exit("southeast","/d/newbie/goblin/rooms/entrance.c","path");
add_exit("north", ROOM "shop9.c","door");
// Exits...
} /* setup() */

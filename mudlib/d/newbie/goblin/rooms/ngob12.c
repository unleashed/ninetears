// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h";

inherit "/std/room";

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
	 "    The tunnel floor here is littered with trash and goblin feces"
" mixed in with large amounts of trash and rotting food. It reminds"
" you of home. The voices comming from camp to the west have gotten"
" louder, as if they are arguing about something.\n\n");
add_property("no_undead",1);
add_sound("voices", " You hear several talking about dinner...old meat");
add_smell("air", "You smell death to the west!!!!!!!!!!!!");
add_item(({"floor"}),
" The floor appears to be littered with all kinds of trash and goblin waste.\n");
add_item(({"trash"}),
"Piles of useless waste, and bones.\n");
add_item(({"feces"}),
" You are really disgusting even for a goblin.\n");
add_item(({"food"}),
"All of this food is coverd with a thick green moss. You might be able to eat it.\n");
add_item(({"wall"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("east","/d/newbie/goblin/rooms/ngob11.c","path");
add_exit("west","/d/newbie/goblin/rooms/ngob13.c","path");
// Exits...

add_clone(CHAR+"drole.c",2);
} /* setup() */

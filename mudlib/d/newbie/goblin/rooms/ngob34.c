// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h"

inherit "/std/room";
object *npc;

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnel");
set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
"     The tunnel gets wider here it is very damp and quiet. Laying in the"
" middle of the floor is a rotting goblin corpse. There does not seem to be "
"a clue as to how he died. To the north you hear the gentle lapping of water"
". The tunnel continues to the south.\n\n");
add_property("no_undead",1);
add_item(({"roof"}),
"There is water dripping fom the stone above your head as you look up"
" some dirty water falls into your eyes blinding you for a moment.\n");
add_item(({"floor"}),
"The floor is compleatly smooth stone except for the occasional"
" pile of goblin excrement.\n");
add_item(({"goblin", "corpse"}),
"This goblin seems to of suffered greatly before he died. "
"His face seemes to be burnt, his eyes look as though they were burnt from his skull.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("north",ROOM+"ngob35.c","path");
add_exit("south",ROOM+"ngob33.c","path");
// Exits...
npc= allocate(4);
} /* setup() */


void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/cave_rat.c");
   npc[i]->move(this_object());
   }
}
}

void dest_me()
{
   int i;
   for(i = 0; i < sizeof(npc); i++)
   {
      if( npc[i] ) npc[i]->dest_me();
   }
   ::dest_me();
}




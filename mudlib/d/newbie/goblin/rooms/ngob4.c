// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h"
inherit "/std/room";
object *npc;

void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Caverns");
   set_light(20);
   set_zone("goblin_newbie");
set_long("\nRealm of the Goblin:  Gloomy Caverns\n\n"
	 "     You are in a dark, damp passage.  The walls here are covered "
	 "with moss and fungus.  The tunnel here gets very narrow.  "
	 "The walls here are very rough like this tunnel was just "
	 "made recently, but then you notice that the floor has been "
	 "worn so smooth that it is obviously been here for a long time.  "
	 "This tunnel was probably never finished since all the dwarf slaves "
	 "died in the fierce battle years ago.  "
	 "To the south you see a less traveled tunnel.  You hear lots of "
	 "noise to the east.  To the west you can just make out a statue in "
	 "the distance.\n\n");
add_property("no_undead",1);
add_item(({"excrement"}),
"Your a goblin alright!!\n");
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

add_exit("south",ROOM+"ngob31.c","path");
add_exit("west",ROOM+"entrance.c","path");
add_exit("east",ROOM+"ngob5.c","path");
// Exits...
npc = allocate(1);
} /* setup() */


void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
npc[i]=clone_object(CHAR+"goblin.c");
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



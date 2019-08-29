// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h"

inherit "/std/room";
object *npc;

void setup() {
// Descriptions...
   set_light(20);
set_zone("newbie_tunnel");
set_short("Realm of the Goblin:  Temple Ruins");
set_long("\nRealm of the Goblin:  Temple Ruins\n\n"
	 "     You have entered the ruins of the temple of Nargar."
" These ruins are full of trash and junk. It appears "
"that someone is using these ruins for a home."
" There is a pile of blankets here that seems to be used for a bed, "
"and several stone blocks that once were used as bases "
"for statues honoring the goblin gods of old."
" The statues have long since crumbled to dust. "
"You seem to sense another prescence. To the south you hear the gentle "
"lapping of water.\n\n");
add_property("no_undead",1);
add_item(({"roof"}),
"There is water dripping fom the stone above your head as you look up"
" some dirty water falls into your eyes blinding you for a moment.\n");
add_item(({"floor"}),
"The floor is compleatly smooth stone except for the occasional"
" pile of goblin excrement.\n");
add_item(({"blocks", "stone", "stones"}),
"Theses large blocks come almost up to your chin. You can only "
"wonder about what the statues looked like that once stood here.\n");
add_item(({"bed", "blankets"}),
"This is a pile of blankets that appears to be used for a bed. It smells of urine.\n");
add_item(({"trash", "ruins", "junk"}),
"There seems to be no end to the amount of junk located in here."
" After digging around looking at pieces of rags and stone"
", you fail to find a single useful item. This definitely is"
" trash even by goblin standards.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("south",ROOM+"ngob35.c","path");
npc= allocate(1);
// Exits...
} /* setup() */



void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/bentneck.c");
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


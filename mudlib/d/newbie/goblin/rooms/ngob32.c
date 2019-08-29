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
	 "     Here the tunnel becomes very narrow and rocky. Water is "
"dripping from the walls and roof. The water is getting you quite dirty"
" and wet, which is really an improvement. You have entered the "
"section of tunnels leading into the less traveled areas. "
"It is said that there is much experience to be gained in this"
" section of tunnels. Where there is much to be learned there"
" is normaly lots of danger for those that are afraid.\n\n");
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

add_exit("east",ROOM+"ngob49.c","path");
add_exit("northwest",ROOM+"ngob31.c","path");
// Exits...
npc=allocate(2);


} /* setup() */



void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/child.c");
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


// The goblin Newbie Area
// Made by Tek and Allonon May 1995
#include "path.h";

inherit "/std/room";

object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Kobold Camp");
   set_light(20);
set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Kobold Camp\n\n"
"     The tunnel comes to a dead end here. There are several young kobolds "
"here arguing about where they are going to get some fresh for dinner."
" As you enter the room they all become very quite and peer at you."
" From the way they are looking at you, you get a good idea of what they are thinking"
" You begin to think that you should run.\n\n");
add_property("no_undead",1);
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

add_exit("east","/d/newbie/goblin/rooms/ngob12.c","path");
// Exits...
       npc=allocate(4);
} /* setup() */



void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/kobold.c");
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


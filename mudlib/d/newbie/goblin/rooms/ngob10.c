// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h"
inherit "/std/room";

object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Gloomy Tunnels");
   set_light(20);
set_zone("newbie_tunnels");
set_long("\nRealm of the Goblin:  Gloomy Tunnels\n\n"
	 "     You are in a dark, damp passage. The walls here are covered "
"with moss and fungus. This part of the tunnels appears to be less"
" traveled than the one to the northeast. The floor is very rough here"
" you can still see marks from the tools that were used to make"
" this tunnel. The floor of this tunnel is littered with small"
" pieces of rock that have broken off the roof and walls hurting"
" your tender young feet. To the northeast you hear voices"
". To the south you see that the tunnel floor gets even rougher"
" you might twist your ankle if you try to go that way. "
" To the northwest the walking looks easier, besides you think"
" you smell fresh water in that direction.\n\n");
add_property("no_undead",1);
 add_sound("voices", "You listen very carefully you think you hear many voices to the northeast.");
add_smell("air", "You smell death to the south!!!!!!!!!!!!");
add_smell("water", "Ahhh you smell fresh water to the northwest");
add_item(({"chips"}),
"These chips are small but very sharp If you're not careful you might"
" cut your feet up and be unable to continue walking. The chips"
" seem to get bigger to the south.\n");
add_item(({"floor"}),
" The floor appears to be littered with small sharp stone chips.\n");
add_item(({"marks"}),
" These tool marks appear as if they have been here for awhile"
". They look like they were made by the picks you saw so many"
" dwarf slaves carrying when you were young.\n");
add_item(({"wall"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("northwest","/d/newbie/goblin/rooms/ngob14.c","path");
add_exit("south","/d/newbie/goblin/rooms/ngob11.c","path");
add_exit("northeast","/d/newbie/goblin/rooms/ngob8.c","path");
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


// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";


object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Dark Cave");
   set_light(20);
   set_zone("newbie_cave");
set_long("\nRealm of the Goblin:  Dark Cave\n\n"
	 "     This cave seems to be someones home, because there is boxes and"
	 " junk laying all around. "
  "There is a pile of furs in the corner that appears to be a bed of some sort. "
    "There is alot of really nice stuff here, nice looking furs, "
   "chests, and a really big mirror leaning on the side of the "
"wall. Who ever lives here must be some sort of a pack rat.\n\n");
add_property("no_undead",1);
add_item(({"boxes", "junk"}),"The boxes are filled with all sorts of "
   "items, most of it is useless junk.\n");
add_item("chests","These chest are really expensive looking, "
  "to bad they are locked. Theres no telling whats in them.\n");
add_item("mirror","You see your reflection. Ugh!\n");
add_item("furs","Some of these furs are really nice, it looks like "
   "the best ones have been made into a bed.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
 "with moss and fungus.\n")+
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items....
add_exit("southwest", ROOM+"ngob41.c","path");
// Exits....
      npc = allocate(1);
} /*setup() */

void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/crookshank.c");
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


// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h";
inherit "/std/room";


object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  River");
   set_light(20);
   set_zone("newbie_river");
set_long("\nRealm of the Goblin:  River\n\n"
	 "     This is the end of the river. This looks like a "
  "home for something because there are bones of all sorts "
  "lying around. This is most likely not a good place to "
"hang around in.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
"with moss and fungus.\n");
add_item("bones","These bones are mostly from cave fish but "
  "you see some goblin bones as well.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("river","This river doesn't look to deep as far as you "
"can tell, maybe about two feet deep. You see some blind fish swimming "
"in it occassionally.\n");
add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
"they look quite tasty.\n");

// Items....
add_exit("southwest", ROOM+"ngob45.c","path");
// Exits....
      npc = allocate(2);
} /*setup() */

void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/eel.c");
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


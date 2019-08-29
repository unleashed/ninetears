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
	 "     You are wading in a river. It is about two and a half feet "
"deep. You can see some sort of natural bridge to the west. "
 "You hear and feel a loud rumbling from the west also. The river flows to the "
"west and southeast.\n\n");
add_property("no_undead",1);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
"with moss and fungus.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");
add_item("river","This river doesn't look to deep as far as you "
"can tell, maybe about two feet deep. You see some blind fish swimming "
"in it occassionally.\n");
add_item(({"fish","blind fish"}),"These are your ordinary cave fish, "
"they look quite tasty.\n");
add_item(({"feet","foot"}),"Your feet are starting to turn purple.");
add_item("bridge","This is a natural stone bridge crossing the "
 "river. To bad you can't get up there so you could dry off.\n");

// Items....
add_exit("west", ROOM+"ngob22a.c","path");
add_exit("southeast", ROOM+"ngob28.c","path");
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
   npc[i]=clone_object("/d/newbie/goblin/npcs/quipper.c");
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

void init() {
add_action("listen_water","listen");
::init();
}
int listen_water(string str) {
if(str=="rumbling") {
write("You hear a loud rumbling sound, it "
"sounds quite disturbing.\n");
tell_room(ENV(TP),CNAME + " seems disturbed listening to the rumbling "
"of the water.\n", (TP));
return 1;
}
}

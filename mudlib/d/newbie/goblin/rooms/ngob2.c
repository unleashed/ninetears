// The goblin Newbie Area
// Made by Tek and Allonon May 1995

#include "path.h"
inherit "/std/room";
string add_long_string;

object *npc;
void setup() {
// Descriptions...
set_short("Realm of the Goblin:  Massive Gate");
set_long("\nRealm of the Goblin:  Massive Gate\n\n"
	 "     You stand before the massive gate of life.  It is so massive"
" that you feel like a bug must feel like to a Goblin.  The gate is locked but"
" it is rumored that if you are experienced enough you may pass through"
" the gate into the life beyond. The gate is guarded by two bugbear guards."
"  To the north lies a meeting place of some kind.  To the south the gate "
"appears to be locked.\n\n");
add_property("no_undead",1);
   set_zone("goblin_newbie");
set_light(45);
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
add_item(({"lock", "inscription"}),
"The lock is small for a gate of this size. Just by looking at it you can tell"
  " that it can not be be picked. The inscription reads only the lonesome one has the power to unlock this lock.\n");
add_item(({"gate"}),
"This large gate is made of the iron that is found here in large deposits"
 ". It is at least 40 feet high. It appears to be locked, the lock appears to be small"
 " so you assume it is locked by some kind of magic. There is an inscription on the lock.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

npc= allocate(2);

   add_exit("north",ROOM+"entrance.c","path");

 add_exit ("south", ROOM + "cave1.c", "gate");
   modify_exit("south",({"function","go_south"}));
}


int go_south ()
{
 object *stuff;

   if(this_player()->query_level() < 5)
   {
     write("The Bugbear snarls and tells you to get your newbie butt back where it belongs.\n");
      return 0;
   }
stuff= find_match("Gate key", this_player());
   if(sizeof(stuff))
  {
   write ("You insert the gate key in the gate, and click, you manage "
	  "to open the gate just enough to slip you through. The gate "
	  "slams shut behind you.\n\n"
"As you leave the Bugbear guards take the key from you."
"\n\n");
stuff->dest_me();
return 1;
   }

else
{

 notify_fail ("You try to open the gate, but it is locked.\n");
 tell_room (environment (this_player ()), this_player () ->
	    query_cap_name () + " tries to go south, but finds the gate "
	    "locked.\n", this_player ());
 return 0;
}
}
void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/goblin/npcs/bugbear.c");
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


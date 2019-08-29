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
	 "     You are in a dark, damp passage. The walls here are covered "
"with moss and fungus. "
"This part of the cavern floor has been worn smooth by the passing "
"of many travelers. There is lots of filth and rubbish laying around"
". Several goblins appear to be passed out cold in this passage,"
" they are laying in pools of half-digested meat and ale."
" To the northeast you hear the clanging of metal on metal "
"you can just barely see the local smithy through all the smoke."
" To the southeast you can hear singing and all kinds of party noise."
" The smell of freshly cooked meat comming from there makes your stomach growl"
".  The tavern looks rather rowdy but you're an adult now so you are sure you will have no problems.\n");
add_property("no_undead",1);
add_item(({"goblin", "goblins"}),
"These goblins are passed out cold. You fish through each drunks"
" pockets looking for valuables but find nothing. Either someone has beaten"
" you to the punch or they drank all they were worth.\n");
add_item(({"rubbish"}),
"You examine the rubbish and find it to be useless garbage.\n");
add_item(({"filth", "pools"}),
"You look closely at the pools of filth you notice"
" that the meat is not very well digested. You are quite tempted to eat it"
" rather then see good meat go to waste.\n");
add_item(({"floor"}),
"It has been worn smooth by many travelers, it is almost hidden by filth.\n");
   add_item(({"wall", "rock"}),
	"The walls here are dark and damp. They are covered "
	"with moss and fungus. Some places there are "
	"bodily wastes smeared up on the walls. The "
	"sight of it is disgusting.\n");
   add_item(({"moss", "fungus"}), 
	"The moss and fungus probably grow here "
	"because the walls are so damp and wet.\n");

// Items...

add_exit("west","/d/newbie/goblin/rooms/ngob4.c","path");
add_exit("northeast","/d/newbie/goblin/rooms/smithy7.c","path");
add_exit("south", ROOM+"tavern6.c","door");
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
   npc[i]=clone_object("/d/newbie/goblin/npcs/bigroach.c");
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


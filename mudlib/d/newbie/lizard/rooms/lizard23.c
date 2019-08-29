/* Added by Galvin 95-05-02 */
#include "path.h"
inherit ROOM+"baseroom";
object *npc;

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	"     You follow the path into a dark part of the swamp. A couple of "
         "twisted trees flank the path on the east side "
         "and a repulsive quicksand blocks all movement to the west. A thick "
         "mist engulfs the path to the south while you can discern some kind "
         "of clearing to the north. Foul vapours rising from the quicksand "
         "make you want to leave this place as soon as possible. \n\n");
add_property("no_undead",1);
add_item(({"vine","vines",}), "These vines are small and harmless. \n\n");
add_item("mist", "The dense mist seems eager to engulf you. \n\n");
add_item("path", "The path seems to disappear in the mist but it's hard to "
         "tell for sure. \n\n");
add_item("quicksand", "The quicksand is disgusting and seems to hunger for "
         "careless adventurers. Foul vapours rise from it, making the air " 
         "hard to breathe. \n\n");
add_item(({"tree","trees",}), "These gnarled trees are covered with the "
         "usual swampmoss that seems to grow everywhere and on everything. "
         "A few vines hang from the trees. \n\n");
add_exit("north",SWAMP +"lizard21","room");
add_exit("northwest",SWAMP +"lizard20","room");
npc=allocate(1);
}


void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
npc[i]=clone_object("/d/newbie/lizard/npcs/gnoll.c");
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


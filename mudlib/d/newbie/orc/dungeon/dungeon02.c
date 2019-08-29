#include "path.h"
inherit CASTLE+"baseroom.c";
object *npc;
void setup() { my_setup();
set_short("Realm of the Orc:  Dungeon Cell");
set_light(40);
set_long("\n   Realm of the Orc:  Dungeon Cell.\n\n"
         "     Compared to the rest of the cells, this one is "
         "appears to be in a decent condition to live in.  Along "
         "the northern wall the is a small cot.  There is a small "
         "door to the south which makes the exit to the passage.  "
         "Like the rest of the cells, it has a dirt floor, and "
         "stone walls\n\n");


add_property("no_undead",1);
add_item(("cot"),"\nThis is an uncomfortable cot that the "
          "used to sleep on.  Through the many years of not using "
          "it, dust has collected and cobwebs have formed.\n");
add_item(("door"),"\nThe door is a solid oak board.  Through the "
          "many years of ageing, the wood is rotting and the "
          "hinges are beginning to rust.\n");
add_item(("floor"),"\nThe flooor here is tightly packed dirt.  "
          "In many locations, you see pile of small stones "
          "stacked\n");
add_item(({"wall","walls"}),"\nThese walls are constructed of "
           "large boulders.  With the sizes of the stones, you "
           "cannot understand how any race of people could "
           "ever build this structure.\n");
add_exit("south",DUNGEON +"dungeon06","door");
npc= allocate(1);
}
 
 
 

void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
   npc[i]=clone_object("/d/newbie/orc/monsters/goul.c");
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


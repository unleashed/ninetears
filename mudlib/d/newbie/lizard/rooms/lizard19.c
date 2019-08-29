/* Added by Galvin 95-05-02 */
#include "path.h"
inherit ROOM+"baseroom";
object *npc;

void setup()  { my_setup();
set_short("Realm of the Lizard:  Musty Swamp");
set_light(60);
set_long("\nRealm of the Lizard:  Musty Swamp\n\n"
	"     You have come to a small three-way crossing. Everything is dark "
         "and damp. Tiny insects are swarming everywhere and especially "
         "around you. A single tree grows here together with a couple of "
         "shrubs and a lot of weeds. Small pools of water make the ground a "
         "bit unstable and muddy. To the east a mist expands as far as you "
         "can see. High-pitched screams can be heard in the distance and you "
         "have second thoughts about venturing farther into the swamp. \n\n");
add_property("no_undead",1);
add_item("tree", "The tree is covered with swampmoss and a few vines seem "
         "to thrive here. \n\n");
add_item("vines", "Quite normal vines that seem happy with their existance. "
          "\n\n");
add_item("insects", "Annoying blood-sucking insects. You try to whisk them "
         "away but to no avail. \n\n");
add_item("shrubs", "They're just that kind of shrubs you could expect in a "
         "place like this. Ugly and covered with thorns. \n\n");
add_item(({"pools","water",}), "There's a huge amount of water in these "
         "parts, much of it probably coming from a pond nearby. \n\n");
add_item("weed", "These weeds seem to grow everywhere. \n\n");
add_item("mist", "It seems to cover a rather big part of the swamp. You "
         "could easily get lost if you stray from the path. \n\n");
add_item("crossing", "The paths leave northwest, east and southwest. The one "
         "to the southwest leads to your homevillage. \n\n");
add_item("ground", "It's soggy and you sink ankledeep in some places. \n\n");
add_exit("northwest",SWAMP +"lizard16","room");
add_exit("east",SWAMP +"lizard20","room");
add_exit("southwest",SWAMP +"lizard22","room");

npc= allocate(2);
}


void reset()
{
int i;
for(i = 0; i < sizeof(npc); i++)
{
   if(!npc[i])
   {
npc[i]=clone_object("/d/newbie/lizard/npcs/lizardmn.c");
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


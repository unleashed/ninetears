#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tunnel");
set_light(40);
set_long("\n   Realm of the Orc:  Tunnel.\n\n"
         "     You seem to be in a cold dark tunnel, there's a faint "
         "light from the gaps "
   "around the hatch you fell through. It looks like someone or several someones "
   "came through here before you. This is fortunate as you seem to be standing "
   "atop a pile of corpses and armour impaled on spikes set into the floor. "
   "It's a rather gruesome sight, but you can comfort yourself with the thought "
   "thats it's better them at the bottom than you. "
   "\n\n");
add_smell(({"air","all"}),"A smell of anchient death pervades the path.\n");
add_item(({"bodies","armour","corpses"}),
   "The bodies are piled high, and appear to have been looted as there is "
   "nothing useful left around here. ");
add_item(({"spike","spikes"}),"The spikes are long, with a wicked barb at the top "
   "the ones you can get a good look at are right up close to the hatch where "
   "the incoming victims have missed them.\n");
add_exit("east",CASTLE +"orc24","path");
add_exit("southwest",CASTLE +"orc26","path");
}

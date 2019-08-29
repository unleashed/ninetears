#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     You seem to walk forever, yet, the scenery, "
		 "if you could call it scenery, has not changed "
		 "in the slightest. The path you are following "
		 "continues onward, deeper into the forest "
		 "\n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("east", GLOOM+"dfo3a", "road");
 add_exit("south", GLOOM+"dfo1a", "road");
add_exit("southeast", GLOOM+"dfo2a", "road");
add_exit("southwest", GLOOM+"dfo1b", "road");
add_exit("west", GLOOM+"dfo1c", "road");
add_exit("northeast", GLOOM+"dfo3b", "road");
 set_zone("forest");
   add_clone(CHAR+"wood_imp",1+random(2));
}


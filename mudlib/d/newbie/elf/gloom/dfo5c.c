#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     As you step into the clearing, your hope turns "
		"to gloom as you realize instead of leaving the "
		"forest you have just ventured deeper into the "
		"heart of the evil forest. The path you have been "
		"following has now totally disappeared. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo5b", "road");
add_exit("northwest", GLOOM+"dfo5d", "road");
add_exit("southwest", GLOOM+"dfo4c", "road");
 set_zone("forest");
   add_clone(CHAR+"wood_imp",random(3));
}


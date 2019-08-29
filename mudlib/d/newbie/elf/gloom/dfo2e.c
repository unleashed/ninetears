#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     This place looks like the rest of the forest "
		"deathly evil. The ground here has been trampled "
		"like possibly something big has been here or "
		"maybe even a fight has taken place. If you "
		"remain here you are liable to find yourself in "
		"trouble or even, *gulp* DEAD! \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southeast", GLOOM+"dfo2d", "road");
 add_exit("southwest", GLOOM+"dfo1e", "road");
add_exit("northeast", GLOOM+"dfo3e", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

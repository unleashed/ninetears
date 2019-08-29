#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     This system of clearings is very interesting.  "
                "Seeing as how they are all closely connected "
                "it leads you to believe that they were laid "
		"out this way as a trap for any unsuspecting "
		"travelers unlucky enough to stumble into this "
		"horrible wretched place. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo3d", "road");
add_exit("southwest", GLOOM+"dfo2e", "road");
add_exit("northeast", GLOOM+"dfo4e", "road");
add_exit("northeast", GLOOM+"dfo3b", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(5)));
}

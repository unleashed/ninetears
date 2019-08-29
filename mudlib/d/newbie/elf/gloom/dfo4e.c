#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     This is another one of those dreaded clearings "
		"This one has massive amounts of blood strewn "
		"around. It looks as if there was a great battle "
		"or slaughter, here. It was recently, the blood is "
		"still fresh. \n\n");            

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southwest", GLOOM+"dfo3e", "road");
add_exit("northeast", GLOOM+"dfo5e", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

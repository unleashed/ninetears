#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     Since you left the clearing the woods have "
		 "returned back to their normal evil looking "
		 "selves. The path you are following heads "
		 "deeper into the woods. You feel the sense of "
		 "evil that once was slightly present grow to a "
		 "full blown fear of the unknown. You feel the "
		 "urge to turn around and run out the way you "
		 "came in! \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo4a", "road");
add_exit("northwest", GLOOM+"dfo4c", "road");
add_exit("northeast", GLOOM+"dfo5b", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

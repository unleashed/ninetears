#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     This clearing is laden with frest blood.  "
		"You can see the skeletal remains of many "
		"Elven warriors laying around. You don't "
		"exactly know what took their lives but it "
		"was not a pleasant death, of that you can "
		"be sure. You start to wonder why you ever "
		"considered coming here alone. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo5c", "road");
add_exit("northwest", GLOOM+"dfo5e", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

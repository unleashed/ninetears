#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     Once again you find yourself in a clearing.  "
		"These woods are full of similar looking places "
		"perhaps they are not clearings at all, maybe "
		"they are feeding places or ambush spots for the "
		"evil that inhabits these woods. \n\n");


add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southwest", GLOOM+"dfo2b", "road");
add_exit("northwest", GLOOM+"dfo3c", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

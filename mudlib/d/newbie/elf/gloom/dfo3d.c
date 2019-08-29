#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     You have entered another clearing.  This one "
		"shows no evidence of attack, and no evidence "
		"of traffic through this part of the woods. You "
		"hear, even louder this time, rustling in the "
		"weeds near you. You should be on your guard a "
		"little more. The path you have been following is "
		"rapidly disappearing. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo3c", "road");
add_exit("northwest", GLOOM+"dfo3e", "road");
add_exit("northeast", GLOOM+"dfo3b", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

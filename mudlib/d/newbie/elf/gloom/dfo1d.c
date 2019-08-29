#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You are in a gloomy, death filled forest.  This looks "
		"very different from the woods you grew up in. "
		"The trees are gnarled and cruel looking one of the "
		"most perverted forms of nature you have ever seen."
		"There are no birds or any pleasant sounds eminating "
		"from these evil woods. \n\n");
	

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southeast", GLOOM+"dfo1c", "road");
 add_exit("northwest", GLOOM+"dfo1e", "road");
add_exit("northeast", GLOOM+"dfo2d", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",1+(random(2)));
}

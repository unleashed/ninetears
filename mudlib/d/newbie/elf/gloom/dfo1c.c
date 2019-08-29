#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You have yet to venture too deep into the woods.  "
		"The perverted looking trees here put a strange "
		"feeling in your soul. You find it difficult to "
		"move about here in these woods, unlike the woods "
		"of you cheerful Elfin home. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("east", GLOOM+"dfo2b", "road");
 add_exit("southeast", GLOOM+"dfo1b", "road");
add_exit("northwest", GLOOM+"dfo1d", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",1+(random(2)));
}

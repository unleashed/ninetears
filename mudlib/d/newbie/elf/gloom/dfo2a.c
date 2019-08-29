#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     The forest seems to go on forever.  You have "
		 "yet to encounter another living soul for miles. A "
		 "sense of forboding evil is present to say "
		 "the least. You think you hear things "
	         "rustling around in the weeds all around you. "
		 "Maybe you should just continue on your way "
		 "and not remain here too long. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southwest", GLOOM+"dfo1a", "road");
 add_exit("northwest", GLOOM+"dfo2b", "road");
add_exit("northeast", GLOOM+"dfo3a", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(2)));
}

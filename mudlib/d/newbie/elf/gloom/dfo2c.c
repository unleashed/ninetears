#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     This place speaks of the most horrid of evils.  Why "
		"are you even here? The ground and trees here seem "
		"conjured instead of grown. There are no birds or "
		"frogs or sounds of any kind of animals.  "
		"\n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("northeast", GLOOM+"dfo3c", "road");
 add_exit("northwest", GLOOM+"dfo2d", "road");
 set_zone("forest");
}

#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You are in a gloomy, forbidding forest.  This looks "
		"very different from the friendly woods you grew up "
		"in.  The trees are gnarled and cruel looking.  The "
		"friendly chirping of birds which you are accustomed "
		"to is noticably absent.  You definately feel "
		"uncomfortable here, as if Elvenkind is not welcome "
                "in these parts."
                "\n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southeast", GLOOM+"dfo1a", "road");
 add_exit("northwest", GLOOM+"dfo1c", "road");
add_exit("northeast", GLOOM+"dfo2b");
 set_zone("forest");
}

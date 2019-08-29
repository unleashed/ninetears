#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You are in a gloomy, forbidding forest.  This looks "
		"very different from the place where you were born, a "
                "hell of a lot more evil than you are used to. You hear "
		"something rustling in the weeds all around you. You feel "
           "a cold chill run up your back.\n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southeast", GLOOM+"dfo2c", "road");
 add_exit("southwest", GLOOM+"dfo1d", "road");
add_exit("northwest", GLOOM+"dfo2e", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

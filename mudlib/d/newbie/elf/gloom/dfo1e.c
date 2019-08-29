#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You start to get the feeling that you are not "
		"alone. For some reason that doesn't make you "
		"feel any better about being here. Maybe you "
		"should go home and get some of your friends "
		"before you go any farther into the evil. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("southeast", GLOOM+"dfo1d", "road");
 add_exit("northeast", GLOOM+"dfo2e", "road");
 set_zone("forest");
add_clone(CHAR+"woop_imp.c",(random(2)));
}

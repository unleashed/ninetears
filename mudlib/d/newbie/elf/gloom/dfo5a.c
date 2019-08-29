#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     This is another ambush waiting to happen.  "
		"These woods are becoming more and more "
		"sinister. With every step you take, the feeling "
		"of your impending demise seems to lodge itself "
		"deeper into your mind and soul. The path you "
		"were following has dwindled into a small "
		"almost invisible trail. \n\n"); 

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southwest", GLOOM+"dfo4a", "road");
add_exit("northwest", GLOOM+"dfo5b", "road");
 set_zone("forest");
}

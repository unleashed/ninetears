#include "path.h"
inherit FORESTROOM;

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     You are in a clearing of this evil forest.  This looks "
		"very different from the friendly woods you grew up "
		"in.  The trees are gnarled and cruel looking.  The "
		"ground here seems down trodden as if it carries "
		"at lot of traffic, although you've yet to see "
		"even a mouse. Maybe the know know smoething you don't. "
		"Once again the paths that leave from here "
		"just continue into the darkness. \n\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southwest", GLOOM+"dfo2a", "road");
add_exit("west", GLOOM+"dfo2b", "road");
add_exit("northeast", GLOOM+"dfo4a", "road");
 set_zone("forest");
add_clone(CHAR+"wood_imp.c",(random(3)));
}

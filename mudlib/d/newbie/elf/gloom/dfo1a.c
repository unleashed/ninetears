#include "path.h"
inherit FORESTROOM;
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest");
set_long("\n   Realm of the Elf:  Gloomy Forest.\n\n"
         "     You are in a dark, damp part of the woods which "
	         "you have never seen the likes of in your life. "
		 "This place is dead silence unlike the cheerful "
		 "woods of your childhood. The trees here are gnarled and "
		 "cruel looking. You have a strange feeling that "
		 "you are not alone here. \n\n");


add_property("no_undead",1);
add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("northeast", GLOOM+"dfo2a", "road");
add_clone(CHAR+"wood_imp.c",1+(random(2)));
add_exit("south", ROOM+"fo3", "road");
add_exit("northwest", GLOOM+"dfo1b", "road");
add_exit("north", GLOOM+"dfo2b", "road");
 set_zone("forest");
}

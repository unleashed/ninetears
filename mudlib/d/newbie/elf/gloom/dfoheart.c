#include "path.h"
inherit ROOM+"quest.c";

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Darkheart");
set_long("\n   Realm of the Elf:  Darkheart.\n\n"
         "     You have entered the heart of the gloomy forest.  Here "
		"lies the center of the evil that has twisted this once "
		"healthy woodland into the gloomy haven for imps it has "
		"now become.  The forest rings a small glen, in the "
		"center of which sits a throne.  From here, Komante sends "
		"his minions to ravage the forest and twist it into "
		"an expanding blight that will take over the elven "
                "homeland."
                "\n\n");
add_item("throne","This is a wooden throne carved by "
		"the wood imps for Komante, their mysterious "
		"master.\n");

add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

 add_exit("north", GLOOM+"dfo5e", "road");
add_clone(CHAR+"geldon",1);
add_clone(CHAR+"komente",1);
 set_zone("forest");
}


#include "path.h"
inherit FORESTROOM;
inherit "/d/hoerk/belaern/s_jung/city/shops/restock.c";
#define NUM 2

void setup()
{
 set_light(60);

 add_property("no_undead",1); set_short("Realm of the Elf:  Gloomy Forest, Clearing");
set_long("\n   Realm of the Elf:  Gloomy Forest, Clearing.\n\n"
         "     This is another one of those conspicuos looking "
		"clearings. It looks the same as the others in "
		"that the ground is down trodden. One thing does "
		"look different from the other clearings, this one "
		"has spots of blood dropped around the center of "
		"clearing as to insinuate an attack from above. "
		"You will be watching above you from now on. \n\n");

add_item("clearing","A small break in the trees.\n");
add_item("blood","Drops of dried blood, its hard to tell what they came from.\n");
add_sound("birds","You wonder why you can't hear any birds. "
		"Perhaps the birds know something you don't.\n");
add_item("tree","The trees are black and twisted.  They seem "
		"to be a perversion of nature.\n");
add_item("sky","You long for a view of the blue sky but alas, "
		"the thick foilage is denying you of even that respite.\n");
add_item("ground","The ground is covered by twisted roots.\n");
add_item("forest","The forest ominously looms around you.\n");

add_exit("southeast", GLOOM+"dfo3b", "road");
add_exit("southwest", GLOOM+"dfo2c", "road");
add_exit("northwest", GLOOM+"dfo3d", "road");
add_exit("northeast", GLOOM+"dfo4c", "road");
 set_zone("forest");
}

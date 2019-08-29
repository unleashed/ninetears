#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     You are on a stretch of tropical beach that runs along the lagoon of the "
"island.  To the west, you see a crude chapel made of bamboo and palm leaves.  "
"to the Southwest, you can just manage a glimpse of the Elder's Hut.  "
"The path veers here, to match the curvature of the island's crescent moon "
"shape.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_item(({"bamboo","palm leaves","leaves","chapel"}),"The Chapel almost looks "
"ready to fall over, but it still serves as the only place for lost spirits "
"to raise themselves on the entier island.  \n");

add_exit("southwest",ROOMS+"elderhouse.c","path");
add_exit("west",ROOMS+"raiserm.c","door");
add_exit("north",ROOMS+"south1.c","path");
add_exit("southeast",ROOMS+"south3.c","path");
}



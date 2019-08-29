#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is the deepest part of the small jungle on this island.  To the East, you "
"can just make out a beach through the plants, and to the South is a better lit "
"section of the forest.  You nearly miss a small cave to the Northwest, but some "
"sort of a snorting sound comes from where it lies hidden in the recess of a cliff.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_item("cave","The cave is dark and you cannot see very far into it from here.  "
"Some sort of snorting sound can be heard within.  \n");
add_sound(({"snort","sound","pig","snorting"}),"The snorting sounds come from the "
"cave within the recess of the cliff.  They sound almost pig-like.\n");
add_item(({"cliff","recess"}),"The cliffs here are far too steep to climb and the "
"one directly to the Northwest has a deep recess in which a cave is nestled.\n");

add_exit("east",ROOMS+"liz9.c","path");
add_exit("south",ROOMS+"liz6.c","path");
add_exit("cave",CAVE+"cave1.c","path");
}



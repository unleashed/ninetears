#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is the Northern-most point of the Crescent Island.  From this ledge "
"one can see ocean in every direction except to the West.  Mamoth rocks jut out "
"from the sea to form the cliffs of this section of the island.  You can also see "
"a massive volcano nestled just outside of the lagoon of the island.  The only ways "
"off of this ledge would be to commit suicide and jump or to return to the West.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_item("volcano","The volcano smokes and spews ash into the air.  Although it has "
"not erupted in centuries, you don't even want to think about what would happen "
"to the small village you were raised in, if it were to erupt.  \n");
add_item("cliffs","The cliffs here are far to jagged to climb up.  \n");
add_item("rocks","The rocks here are mostly verticle and impossible to climb up.  "
"A fall down on the rocks would most likely wind up severing you in half against "
"the sharp shale and metamorphic rocks.  \n");
add_item("lagoon","The lagoon is protected on all sides except the East by the "
"island.  It has a light blue tint to the water and is relatively calm.  \n");

add_exit("west",ROOMS+"liz9.c","path");
}



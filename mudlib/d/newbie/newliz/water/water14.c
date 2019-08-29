#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     You are on a rocky land bridge which leads out to the volcano that created "
"the crescent island.  The sides of this bridge are all crubling from years of the "
"ocean's wave action against the rock and do not appear to be in good shape.  To "
"either side of you is about a 400 drop straight down.  From the pressure on your "
"eardrus at this time, you can just imagine what would happen down there.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item("bridge","The land bridge is crumbling with every step you take on it.  \n");
add_item("rock","The rock underfoot is volcanic and would most likely be dicing "
"your feet to shreds if not for all the calice from the hot sand.\n");
add_item("drop","The drop is straight down to the point that you are unable to see "
"the bottom of it.\n");

add_exit("south",WATER+"water13.c","path");
add_exit("north",WATER+"water15.c","path");
}



#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     The floor of the ocean abruptly drops about two-hundred feet down into "
"pitch blackness before you.  The pressure down there would probably be sufficient "
"to squash you like a grape.  Deciding against this quick end, you quickly assess "
"the remaining routes open as being to the West, Northwest, and North.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"blackness","darkness","dark","cliff","drop","drop-off"}),"The drop-off "
"before you is far to great to survive, and even if you did, the pressure down "
"there would most likely kill you.\n");
add_item("grape","Actually, there isn't a grape here.  That's just a figure of speech.\n");

add_exit("west",WATER+"water2.c","path");
add_exit("northwest",WATER+"water7.c","path");
add_exit("north",WATER+"water8.c","path");
}



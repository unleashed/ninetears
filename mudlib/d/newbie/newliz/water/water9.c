#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater \n"
"     The water here is relatively shallow, but the rocks along the shoreline to "
"the west make it impossible to surface safely in that direction.  To your northwest, "
"there appears to be a small cave-like indentation within one of the massive "
"boulders which encircle the island.  Any direction to the East taes you into deeper "
"waters.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item("rocks","The rocks here are jagged and sharp to the touch.  There is a "
"curious hole within one of them that you could most likely fit into.\n");
add_item(({"cave","hole"}),"You could, most likely, squeeze into the narrow opening "
"of this hole and see what was inside.  \n");
add_feel("rocks","%^RED%^Ouch!%^RESET%^  You should be more careful touching "
"sharp rocks!\n");

add_exit("southwest",WATER+"water5.c","path");
add_exit("south",WATER+"water6.c","path");
add_exit("southeast",WATER+"water7.c","path");
add_exit("east",WATER+"water10.c","path");
add_exit("northeast",WATER+"water12.c","path");
add_exit("cave",WATER+"watercave.c","path");
}



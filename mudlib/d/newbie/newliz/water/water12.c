#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     This stretch of the lagoon is flanked to the North by the sharp cliffs "
"which rise from the ocean and extend far above.  The terrain makes it quite "
"imposible for you to climb the rock face and severly limits your movement "
"options.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item(({"face","cliff","rock face"}),"This cliff is verticle and extends high above the waves.\n");
add_item("waves","The waves move lazily above you from East to West.\n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");

add_exit("southwest",WATER+"water9.c","path");
add_exit("south",WATER+"water10.c","path");
add_exit("southeast",WATER+"water11.c","path");
add_exit("east",WATER+"water13.c","path");
}



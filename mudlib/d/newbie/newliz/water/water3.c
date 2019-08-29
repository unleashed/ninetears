#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     This section of the underwater slopes sharply towards the East.  The lagoon "
"floor is also beginning to become much less granular and more sandy as you move "
"towards where the ocean meets the beach to the West.  To the South and Southwest, "
"jagged rocks rise out of the floor of the ocean block your path.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item("rocks","These rocks are mostly volcanic in nature and prevent any safe "
"route to the beach above the waves.\n");
add_item("slope","The slope seems to level off further towards the East.\n");


add_exit("east",WATER+"water2.c","path");
add_exit("northeast",WATER+"water7.c","path");
add_exit("north",WATER+"water6.c","path");
add_exit("northwest",WATER+"water5.c","path");
}



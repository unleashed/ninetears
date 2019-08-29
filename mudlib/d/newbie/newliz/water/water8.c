#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     Other than the massive drop-off to the East, this area is rather bleak.  The "
"sand here, however is begenning to become a slight bit warmer than it had been.  "
"The cliff to the East goes straight down into the darkness below, signifying the "
"end of Crescent Island's lagoon.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"sand","ground","floor"}),"The sand here is begining to heat up.  It "
"seems a tad peculiar, seeing as how it has been getting cooler up to this point.\n");
add_item(({"cliff","darkness","drop-off","drop","dropoff"}),"This cliff must go "
"at least 200 feet, or more, straight down.  Obviously the bottom of it wouldn't "
"be a good place to wind up.\n");
add_item("bleak","The entire area is composed of nothing more than gray and brown "
"sand with the occasional coral or rock protruding.  Pretty bleak.\n");

add_exit("south",WATER+"water4.c","path");
add_exit("southwest",WATER+"water2.c","path");
add_exit("west",WATER+"water7.c","path");
add_exit("northwest",WATER+"water10.c","path");
}



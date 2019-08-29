#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     You are standing on the most Southwestern part of the island which is "
"reachable by foot.  Massive cliffs spring up to the west and hook to the south "
"areas of the island.  The only way to go, here is to the east, out towards the "
"lowest point of the crescent island, and to the Northwest.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_exit("east",ROOMS+"south10.c","path");
add_exit("northwest",ROOMS+"south7.c","path");
}



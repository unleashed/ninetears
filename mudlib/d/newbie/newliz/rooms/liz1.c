#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is the large beach of the island which you have lived on for all of your "
"life.  It has no name, for that is something for humans, not for lizard-men.  "
"The beach runs to the north and south, along the ocean.  The training hut "
"for those of your tribe is to the east.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_item(({"ocean","water","rocks"}),"The rocks in the water make it too dangerous "
"to go swiming along this section of the beach.\n");
add_exit("north",ROOMS+"liz2.c","path");
add_exit("west",ROOMS+"guild.c","door");

}



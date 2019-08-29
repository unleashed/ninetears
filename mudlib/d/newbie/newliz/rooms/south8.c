#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is a beach, pretty much the same as every other beach which "
"you've seen around the lagoon of the Crescent Island.  This section, however, is "
"becoming particularly rocky, and seems to jab upward, further to the South.  "
"A very dense section of jungle is to the West, effectively blocking any attempt "
"to enter, there.  The beach itself expands and continues to the Northwest.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_exit("south",ROOMS+"south10.c","path");
add_exit("northwest",ROOMS+"south6.c","path");
}



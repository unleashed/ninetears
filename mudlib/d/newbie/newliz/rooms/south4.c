#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The beach you are on takes a sudden split at this point.  The beach, itself, "
"continues to the south.  However, to the southwest, there is a small path a "
"little ways into the jungle of the island.  You also notice that the lagoon, "
"while still not safe to dive into, seems to be calming its waters, slightly.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_exit("southwest",ROOMS+"south5.c","path");
add_exit("south",ROOMS+"south6.c","path");
add_exit("northwest",ROOMS+"south3.c","path");
}



#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The island continues to stretch to the West and East, making a slight "
"curve as it goes, thus giving it the name 'Crescent Island.'  The beach is "
"gradually getting thinner and thinner off to the East, while off to the West, "
"you can just see jungle springing up towards the island's interior.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_exit("east",ROOMS+"south12.c","path");
add_exit("west",ROOMS+"south10.c","path");
}



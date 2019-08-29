#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is the begining of the southern section of the island's beach.  "
"To your west, you can see a small grass hut from which you hear a "
"fellow lizard shifting some weapons or armours around.  The beach continues "
"north and south, and the great ocean winds off to the east.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_item(({"ocean","water","rocks"}),"The ocean is too dangerous to swim in here "
"because of the rocks within the churning water.\n");

add_exit("north",ROOMS+"liz1.c","path");
add_exit("west",ROOMS+"shop.c","door");
}



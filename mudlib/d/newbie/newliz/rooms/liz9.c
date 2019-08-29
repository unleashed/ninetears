#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The beach has become nearly non-existant at this point.  Rocks from the "
"surrounding cliffs dominate the area more than the sand of where the ocean meets "
"the land.  There is a small, rocky ledge to the Northeast and much nicer looking "
"beach to the South.  To the West is a very dense, dark, and forboding section of "
"the island's jungle.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_item("ledge","The ledge seems safe enough, although lizards are known for "
"their ability to hold their breath, not climb mountains.  \n");

add_exit("south",ROOMS+"liz7.c","path");
add_exit("west",ROOMS+"liz8.c","path");
add_exit("ledge",ROOMS+"liz10.c","path");
}



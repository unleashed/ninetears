#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The beach continues to run to the parallel to the cliffs of the island, here.  "
"Although you cannot see the tops of them, to the West, they look quite impassable.  "
"The rocky coast continues to the east and the warm sand runs along the water.  "
"Small birds you recognize as seagulls fly overhead.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");

add_item(({"birds","seagulls","small birds"}),"*SPLAT!*  As you look up, your "
"head is greeted with a warm, moist gift from one of the seagulls.  Cursing, "
"you wipe the slime from your scalp and swear to kill the next gull you see.\n");

add_exit("northwest",ROOMS+"south2.c","path");
add_exit("south",ROOMS+"south4.c","path");
}



#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The sand on this section of the beach seems to take on a rocky sensation.  "
"As you look to the west, you can clearly see why.  The cliffs have begun to lower and "
"arc towards the sandy beach.  Some jungle stands between you and the rocks, though.  "
"To your immediate west there is dense jungle which cannot be penetrated from this "
"angle.  Perhaps the Northerly route which leads into the green plants would be "
"better.  There is also a continuation of the beach to the Northeast and Southwest.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"Although nearly unnoticable, the sand seems "
"a bit more coarse on your bare feet.  \n");
add_item("jungle","The jungle is off to the West and seems far to dense to venture "
"into from here.  The sounds of animals can be heard from the lush vegetation. \n");
add_sound(({"jungle","sounds","animals"}),"The animals seem to be chattering "
"incoherently and making a lot of useless noise.  \n");

add_exit("north",ROOMS+"liz6.c","path");
add_exit("northeast",ROOMS+"liz7.c","path");
add_exit("southwest",ROOMS+"liz3.c","path");
}



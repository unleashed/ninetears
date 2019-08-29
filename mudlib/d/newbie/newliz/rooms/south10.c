#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     This is the start of the Eastern push of Crescent Island.  There are no "
"more rocky cliffs to be seen, just ocean on either side of the beach.  There is "
"a path to the West that leads deep into the heart of the island's jungle.  To "
"the East and North are sandy beaches.  The only sounds to be heard are those "
"of seagulls and waves crashing along the beach.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
 add_feel(({"sand","floor","ground"}),"The ground is very hot and almost singes "
"your feet.  \n");
add_sound("seagulls","The birds occasionally call out, but the sound is more of "
"a nuissance than anything else.  \n");
add_sound("waves","The waves hit the beach and the rocks in the ocean with a "
"thunderous boom!  \n");

add_exit("west",ROOMS+"south9.c","path");
add_exit("east",ROOMS+"south11.c","path");
add_exit("north",ROOMS+"south8.c","path");
}



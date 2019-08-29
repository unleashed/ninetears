#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Lizard's Island:  Beach\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard's Island:  Beach\n\n"
"     The path through here goes slightly into the jungle, then is blocked with "
"tropical trees, forcing you to either go to the northeast or to the east.  "
"You nearly miss a side path which veers off to the South, further into the "
"jungle, as well.  "
"The only thing that breaks the silence, away from the crashing of the ocean, is "
"the occasional bird call.  "
    "\n\n");

add_item("shells","These shells are common all over the island and are frail to "
"the touch.\n");
add_item("sun","The sun beats down from above.  It feels good to a lizard, such "
"as yourself.\n");
add_feel(({"sand","floor","ground"}),"The ground is very hot, and the sand hot "
"to the touch of your feet.\n");
add_sound(({"birds","call","song","sounds"}),"The bird calls are too far and few "
"between for there to be any real melody to them.  You cannot even catch a "
"glimpse of the feathered animals as they flit about overhead.\n");
add_item("birds","The birds are moving too quickly, overhead, for you to catch "
"a decent glimpse of them.\n");
add_item(({"jungle","trees","foilage"}),"The underbrush and tropical plants are "
"too thick and fleshy to cut through, here.  \n");

add_exit("northeast",ROOMS+"south4.c","path");
add_exit("south",ROOMS+"south7.c","path");
add_exit("east",ROOMS+"south6.c","path");
}



#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     The ocean floor takes a rather steep dip to the East.  Namingly, one that is "
"straight down into darkness.  There is also a very narrow underwater land bridge "
"which seems to attach to the lagoon at this point and lead off to the North.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"bridge","land bridge","underwater bridge"}),"This narrow passage of "
"rocks is all that remains from where the volcano originally formed the Crescent "
"island.\n");
add_item(({"dip","cliff","fall"}),"This is one dip you're glad you see the signs for "
"ahead of time.  It looks to be over 400 feet or more straight down.\n");

add_exit("southwest",WATER+"water10.c","path");
add_exit("north",WATER+"water14.c","path");
add_exit("west",WATER+"water12.c","path");
add_exit("south",WATER+"water11.c","path");
}



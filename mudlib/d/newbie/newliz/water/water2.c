#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     This section of the underwater is a little deeper than the area to the "
"South.  It is also a little more rocky than before, reminding you of the volcanic "
"origins of the island.  There are several different kinds of coral scattered "
"throughout the area.  An occasional fish will swim by, seemingly ignoring you.  "
"Because of the terrain underwater, you can go in just about any direction, although "
"to the South seems to incline towards the surface more than others.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item("coral","The occasional coral you spot range in colors from red to yellow "
"to green and purple.  \n");
add_feel("coral","You decide against touching the coral knowing that it would "
"probably kill the plant, and that a few have poisonous stingers.\n");
add_item("fish","The fish which dart by are the ones you are most familiar with in "
"these tropical regions, and most are the stereotypical wild colors.\n");
add_item("rock","The rocky floor here is probably due to the fact that the waves "
"are not felt so much at this depth.\n");

add_exit("south",WATER+"water1.c","path");
}



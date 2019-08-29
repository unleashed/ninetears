inherit "/std/room";
#include "path.h"

void setup()
{
set_short("Lizard Domain:  Cavern\n\n");
set_long("Lizard Domain:  Cavern\n"
"     This is the entrance to a dank cave, one of many, on the Crescent Island.  "
"The light in here makes it difficult to see, but a little bit of light reflecting "
"from the not-so-distant ocean makes it easier.  You can clearly see the cave's "
"exit to the Southeast and a passage that goes deeper into the cavern to the "
"North.  "
"\n\n");

add_item("rocks","The rocks of this cave are primarily shale and volcanic in "
"their nature.  Both types are VERY sharp to the touch.\n");
add_feel(({"rocks","shale","volcanic rock","volcanic"}),"You decide against "
"grasping the rock after realizing just how sharp it is.\n");

add_exit("out",ROOMS+"liz8.c","path");
add_exit("north",CAVE+"cave2.c","path");
}

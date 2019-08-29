inherit "/std/room";
#include "path.h"

void setup()
{
set_short("Lizard Domain:  Cavern\n\n");
set_long("Lizard Domain:  Cavern\n"
"     The cave abruptly dead ends here.  There are massive scrapings along the walls "
"from where an animal of some sort has sharpened its claws on the rocks.  "
"The marks seem to have been built up over many years of scratching.  "
"\n\n");

add_item(({"rocks","scratches","claw marks"}),"The marks are several inches apart "
"and appear to have been made by a VERY massive animal.  \n");
add_feel(({"rocks","shale","volcanic rock","volcanic"}),"You decide against "
"grasping the rock after realizing just how sharp it is.\n");

add_exit("south",CAVE+"cave2.c","path");
}

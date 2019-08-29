inherit "/std/room";
#include "path.h"

void setup()
{
set_short("Lizard Domain:  Cavern\n\n");
set_long("Lizard Domain:  Cavern\n"
"     Being deeper into the cave, this small passage is a little darker than the "
"room to the South.  There is still enough light to see that the passage forks at "
"this point, though.  To the Northwest you can hear some sort of scraping noises.  "
"The Northeast passage has a strange scent coming from its depts as wells as some "
"sort of a hoof print trail running in the soil.  "
"\n\n");

add_item("rocks","The rocks of this cave are primarily shale and volcanic in "
"their nature.  Both types are VERY sharp to the touch.\n");
add_feel(({"rocks","shale","volcanic rock","volcanic"}),"You decide against "
"grasping the rock after realizing just how sharp it is.\n");
add_item(({"prints","hoof prints","hoof","trail"}),"The trail is well-worn and "
"seems to have been made over an extended period of time.  \n");
add_smell(({"scent","strange scent"}),"The smell is something like a rotten "
"vegetation and pig crap.  \n");

add_exit("south",CAVE+"cave1.c","path");
add_exit("northeast",CAVE+"cave4.c","path");
add_exit("northwest",CAVE+"cave3.c","path");
}

inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Cave of Gloom:  Branching Path\n");
set_long("Cave of Gloom:  Branching Path\n"
"     The cave slopes continually upward to the north and to the east.  To the south "
"there appears to be some kind of a large room.  Scraping noises fill the cave in a "
"melody of eeriness and fright.  You can just make out a shadow of something to the "
"north, as well.  "
"\n\n");

set_light(80);
add_item("shadow","You cannot quite tell what it is from here, maybe you should go closer?\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_sound(({"noise","scraping","fear","eeriness","echo"}),"The noises bounce off of "
"the walls, making it difficult to pinpoint the sound, but it appears to come from the "
"East.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("south",CAVES+"cave8.c","path");
add_exit("north",CAVES+"cave12.c","path");
add_exit("east",CAVES+"cave11.c","path");
}

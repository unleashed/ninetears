inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Cave of Gloom:  Passage\n");
set_long("Cave of Gloom:  Passage\n"
"     In this area, the walls all seem to be losing their webbing, and where "
"gossamer once was, it is being replaced with dripping water.  The atmosphere of the "
"cave has taken on a musty, ancient feeling.  This, along with the almost total "
"lack of light makes the whole time down here even less bearable.  "
"\n\n");

set_light(80);
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");

add_clone(CHAR+"baby_spider",2);
add_exit("south",CAVES+"cave2.c","path");
add_exit("north",CAVES+"cave7.c","path");
}

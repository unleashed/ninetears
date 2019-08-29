inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Winding Passage");
set_long("Winding Passage\n\n"
"     The cave takes a very sharp turn to the West and South here.  The water which "
"is dripping from the ceiling has become cooler, and everything seems damp down here.  "
"In the darkness, you can still hear the echos of something being grated further to "
"the west.  "
"\n\n");

set_light(80);
add_item("water","The water is dripping from every crack and crevice in the cave.\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_feel("water","The water is ice cold to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_sound("sound","As you strain to hear, you think the sound might be something large being dragged. \n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");

add_clone(CHAR+"baby_spider",1);
 add_exit("south",CAVES+"cave7.c","path");
add_exit("west",CAVES+"cave8.c","path");
}

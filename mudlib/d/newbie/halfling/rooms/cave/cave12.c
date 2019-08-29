inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Spider's Crypt\n");
set_long("Spider's Crypt\n"
"     The cave takes a very sharp turn to the West and South, here.  The water which "
"is dripping from the ceiling has become colder and everything seems damp down here.  "
"In the darkness, you can still hear the echos of something being grated further to "
"the West.  "
"\n\n");

set_light(80);
add_item("web","The web here is old and tattered.  It hasn't been spun in a long "
"time, by the looks of things.\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_feel("water","The water is ice cold to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("south",CAVES+"cave10.c","path");

add_clone(MISC+"deadspider.c",1);
}

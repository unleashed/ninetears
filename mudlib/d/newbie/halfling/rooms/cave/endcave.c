inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("dead end");
set_long("\nDead End in the Cave of Gloom.\n\n"
"     This is a dead end in several aspects. First, the only exit is through the way you came in. Second, there is piles of bones strewn "+
"along the cave floor. It is hard to remain calm here because of the constant echo of death around you. "+
"The walls are an unusal shade of brown. There is a few small patches of moss on the ceiling, "+
"but it is much darker here than in the other sections of the cave.\n\n");

set_light(80);
add_item("bones","These appear to be the bones of halflings. A few of them are still relatively new.\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("south",CAVES+"cave11.c","door");
add_clone(CHAR+"endboss.c",1);
}

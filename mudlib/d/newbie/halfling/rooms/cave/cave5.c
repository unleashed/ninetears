inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Cave of Gloom:  Winding passage.\n");
set_long("Cave of Gloom:  Winding Passage\n"
"     In this part of the cave, the passage comes to an abrupt end where it appears "
"there has been a cave-in.  It looks as though you'll have to backtrack to the South.  "
"\n\n");

set_light(60);
 add_item(({"cave-in","rocks","end","dead end","abrupt end"}),"The rocks to the east must "
"weigh a ton, judging by their appearance.  As you inspect them, your hand actually "
"passes THROUGH one the rocks.  It seems the whole cave-in is an illusion.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("south",CAVES+"cave3.c","path");
add_exit("rocks",CAVES+"cave6.c","hidden");
add_exit("east",CAVES+"cave6.c","hidden");
add_exit("cave-in",CAVES+"cave6.c","hidden");

}

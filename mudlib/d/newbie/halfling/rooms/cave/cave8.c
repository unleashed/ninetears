inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Cave of Gloom:  Room\n");
set_long("Cave of Gloom:  Room\n"
"    You have stumbled into a large cave room. The walls go up around forty feet, "
 "and the room is around sixty feet across. An immense spider web decorates the ceiling, "
"but looks old and tattered.  There is a passage to the east and to the north. The "
"ground is starting to slope upward at this point.  "
"\n\n");

set_light(80);
add_item("web","The web is around thirty feet up, and spans the entire room.  You "
"get the feeling you don't want to meet what made it.\n");
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("slope","The slope to the north slants upward, mostly like slopes do.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("east",CAVES+"cave9.c","path");
add_exit("north",CAVES+"cave10.c","path");
}

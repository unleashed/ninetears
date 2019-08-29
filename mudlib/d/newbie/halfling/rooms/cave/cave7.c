inherit "/std/room.c";
#include "path.h"
void setup()
{
set_short("Downward Passage");
 set_long("\nDownward slope in the Cave of Gloom.\n"
"     This section of the cave takes an abrupt downward turn.  The wet conditions of the "
"floor makes it even more difficult to keep traction enough not to slide down the "
"slight incline.  Further down the slope, you can see a branch ahead, and an eerie "
"sound echos throughout the cave."
"\n\n");

set_light(60);
add_item("wall","Upon further inspection, the brown substance on the wall appears to be dried blood.\n");
add_item("moss","The phospherescent moss covers the cave in small patches"+
"imbedded into the ceiling providing barely enough light to see.\n");
add_sound("sound","You can't be sure of what is making that sound, but it's close.\n");
add_feel("wall","The wall is slimy to the touch.\n");
add_smell("cave","The cave smells musky and earthy, the way all caves smell.\n");
add_feel("moss","Try as you might, the moss is too high to reach.\n");
add_exit("south",CAVES+"cave4.c","path");
add_exit("north",CAVES+"cave9.c","path");

add_sound(({"room","echos","echo","noise"}),"The echos sound like bone being grated "
"against rock.  A most peculiar, and frightening, sound.\n");
}

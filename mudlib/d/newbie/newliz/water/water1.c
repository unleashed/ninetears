#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     This is a very shallow section of the underwater area.  The lagoon slopes "
"down from here.  Light from the sun creats a cascade effect due to the waves "
"above.  An occasional fish swims by and stares at you questioningly, as if to ask "
"why on earth you are down here.  The water is very warm upon your skin.  The "
"spell the elder cast upon you seems to be working, seeing as how you are breathing "
"normally beneath the surface.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item("fish","The fish seems to stare at you with bulging eyes.  It is red and "
"gold in its coloration and very vertically oriented.  The fish's tail is almost as "
"long as the fish's body is.  \n");
add_feel("fish","As you reach out to touch the fish, it rapidly darts out of your "
"way.  \n");
add_item("slope","The floor of the lagoon is sloping to the North.  There is also "
"a very warm current from that direction.  \n");
add_item("sun","The sun isn't very visible from even this shallow depth.  For the "
"most part, the waves are masking the image of the sun above.\n");

add_exit("north",WATER+"water2.c","path");
add_exit("up",ROOMS+"south12.c","path");
}



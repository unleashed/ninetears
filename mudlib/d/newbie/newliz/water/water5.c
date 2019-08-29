#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     This is the closest you can get to the beach.  From here, you can barely see "
"through the bubbles from the waves to the West, which leads to the beach.  However, "
"coming back down would be another story.  The rocks and inability to see clearly "
"make it far to dangerous to re-enter the water at this point, thus returning to "
"dry ground would be a one-way ticket, here.  The oean deepens in every other "
"direction to the East at this point.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"bubbles","waves","beach"}),"You cannot get a clear picture of what is "
"ahead of you to the West, but it appears to be the central beach of the Crescent "
"Island.\n");
add_item("rocks","The rocks are volcanic in their origin.  Some are submerged and "
"others are jutting above the water.\n");

add_exit("west",ROOMS+"liz1.c","path");
add_exit("northeast",WATER+"water9.c","path");
add_exit("east",WATER+"water6.c","path");
add_exit("southeast",WATER+"water3.c","path");
}



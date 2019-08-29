#include "path.h"

inherit "/std/room";
void setup()
{
set_short("Lizard Domain:  Underwater\n");
set_light(LIGHT);
add_property("no_undead",1);
set_long("Lizard Domain:  Underwater\n\n"
"     The ocean floor here is relatively non-descript, other than the mammoth "
"hole between two rocks and the number of broken sea shells and body parts of "
"several marine creatures scattered around the hole.  You also notice some tracks "
"in the sand that resemble several snakes traveling side-by-side.  From your "
"experience with ocean wildlife, you recognize this as an octopus den.  Every "
"route is open to you except the South, which has a small wall of coral blocking "
"your passage.  "
    "\n\n");

add_item("water","The water is crystal clear, as is most ocean water in the "
"tropical regions of the world.  \n");
add_item("light","The sun above provides natural lighting beneath the surface "
"of the waves.\n");
add_feel(({"sand","floor","ground"}),"The sand is very soft and worn from the "
"continuous action of the waves.\n");
add_item(({"hole","cave"}),"This hole between the rocks is entirely too small for "
"you to journey into, but is the perfect size for something that has no skeleton, "
"like an octopus.\n");
add_item(({"rock","rocks"}),"The two rocks here are in an inverted 'V' design.  "
"Between them, there is a small hole ideal for something to live in.\n");
add_item(({"shells","broken shells"}),"These shells have been ripped open by a "
"powerful tug or actually bitten through by something sharp and extremely strong.\n");
add_item("tracks","These tracks are definately those of an octopus as it skims "
"the bottom of the lagoon in search of food.\n");
add_item(({"body parts","parts","legs","bones"}),"You distinctly recognize some of "
"the body parts here as being crab legs, bones from large fish, and various other "
"pieces of aquatic life which aren't suited too well for being eaten.\n");

add_exit("southwest",WATER+"water3.c","path");
add_exit("southeast",WATER+"water4.c","path");
add_exit("west",WATER+"water6.c","path");
add_exit("east",WATER+"water8.c","path");
add_exit("northeast",WATER+"water11.c","path");
add_exit("north",WATER+"water10.c","path");
add_exit("northwest",WATER+"water9.c","path");
}



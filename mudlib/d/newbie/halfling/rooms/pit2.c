#include "path.h"
inherit "/std/room.c";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Entrance to the Pit.");
 set_long("Island of Maroek:  Entrance to the Pit\n\n"
"The second you go under the sand and arrive here, you realize that it may have been "
"the biggest mistake of your life, or what's left of it.  A terrible monster dwells "
"in this place, and your mind starts to wonder how plausable it would be to climb "
"back up.  Sand falls all around you, and there are skeletons of animals strewn about "
"the entire area of this cave.  "
"\n\n");
add_item("sand","The sand streaming from above would be enough to trap a normal "
"animal down here, but a halfling is well known for being VERY agile.  \n");
add_clone(CHAR+"sandlion.c",1);

add_exit("up",ROOMS+"pit.c","path");
}



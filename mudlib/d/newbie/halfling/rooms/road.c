#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You are on the a road that travels north, to the forest and west to the Halfling Square.  The road is dusty, and travelworn.  "
"Tree coverage along this road is a minimum, allowing the sunlight to reach the ground "
"below.  "
    "\n\n");

add_clone(CHAR+"bad_dog.c",3);
add_exit("west",ROOMS+"square.c","path");
add_exit("north",ROOMS+"half5.c","path");
}



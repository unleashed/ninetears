#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You have wandered into Maroek's forest.  The thoughts of dying in this place don't "
"exactly appeal to you, so you are continually watching your step along this path. "
"To the south, you can see a path running east and west, but otherwise, you cannot "
"see the forest for the trees.  "
    "\n\n");

add_exit("north",ROOMS+"half13.c","path");
add_exit("southwest",ROOMS+"half1.c","path");
add_exit("south",ROOMS+"half2.c","path");
}



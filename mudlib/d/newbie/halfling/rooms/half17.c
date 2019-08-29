#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"This is the very heart of the forest.  Green trees seem to sprout all around you.  "
"There is a clearing to your north with only knee high grass.  "
    "\n\n");

add_exit("southwest",ROOMS+"half13.c","path");
add_exit("southeast",ROOMS+"half14.c","path");
add_exit("north",ROOMS+"half20.c","path");
add_exit("northwest",ROOMS+"half19.c","path");
}



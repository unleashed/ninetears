#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You are wandering about in the Maroek Forest.  The trees are a lush green in the "
"pseudo-tropical climate of this island.  You can just make out a path to your "
"south, on the edge of the forest."
    "\n\n");

add_exit("south",ROOMS+"half3.c","path");
add_exit("northeast",ROOMS+"half14.c","path");
}



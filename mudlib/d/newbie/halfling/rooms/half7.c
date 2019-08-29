#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You have wandered into the Maroek forest.  Though not the most dangerous place "
"on this small island, it does lead to the more dangerous places.  To the south, "
"you can just manage to see a path.  "
    "\n\n");

add_exit("west",ROOMS+"half6.c","path");
add_exit("northeast",ROOMS+"half13.c","path");
add_exit("northwest",ROOMS+"half12.c","path");
add_exit("south",ROOMS+"half1.c","path");
}



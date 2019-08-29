#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"You find yourself in the dreaded Forest of Maroek, from which few have returned.  "
"Not far to your South, though, you can see the beginings of civilization and a road "
"running parallel to the forest.  Other than that, there is little to notice besides "
"the trees and small animals running to and fro.  "
    "\n\n");

add_clone(CHAR+"buzzard.c",1);
add_exit("west",ROOMS+"half10.c","path");
add_exit("south",ROOMS+"half5.c","path");
add_exit("north",ROOMS+"half15.c","path");
}



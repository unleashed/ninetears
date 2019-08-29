#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"All is peaceful here.  You find yourself daydreaming as you meander along the "
"paths, and almost miss a small door in a tree to your south.  The door has the "
"symbol of a glass of ale upon it.  "
    "\n\n");

add_clone(CHAR+"buzzard.c",2);
add_exit("west",ROOMS+"half1.c","path");
add_exit("south",ROOMS+"tavern.c","door");
add_exit("north",ROOMS+"half8.c","path");
add_exit("east",ROOMS+"half3.c","path");
}



#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"The forest is hot and humid.  The wildlife appears to be keeping its distance, though "
".  To your north is a cave leading into the mountain which rises out of the forest.  "
"The south is the only other path not completely overgrown with vegetation.  "
    "\n\n");

add_clone(CHAR+"hedge_wizard.c",1);
add_exit("cave",CAVES+"cave1.c","path");
add_exit("south",ROOMS+"half12.c","path");
}



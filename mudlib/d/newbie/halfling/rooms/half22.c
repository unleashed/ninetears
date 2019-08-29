#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"This is almost as far to the north and east you can go on your tiny island.  Legends "
"tell of a terrible beast which dwells in this remote corner of the forest.  You begin "
"to have second thoughts about venturing much further to the north.  "
    "\n\n");

add_clone(CHAR+"hedge_wizard",2);
add_exit("west",ROOMS+"half21.c","path");
add_exit("north",ROOMS+"half25.c","path");
}



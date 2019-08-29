#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"This path runs mostly north and south.  To your east is a small clearing.  The forest "
"becomes much more dense to your Northwest, though.  "
    "\n\n");
add_exit("southeast",ROOMS+"half17.c","path");
add_exit("east",ROOMS+"half20.c","path");
add_exit("northwest",ROOMS+"half23.c","path");

}



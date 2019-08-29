#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"This is a north-south path.  Further to the North, you can see a mountain "
"rising up.  Dense vegetation grows everywhere else, except on the path you currently "
"travel upon.  "
    "\n\n");

add_clone(CHAR+"bear.c",3);
add_exit("southeast",ROOMS+"half7.c","path");
add_exit("north",ROOMS+"half16.c","path");
add_exit("south",ROOMS+"half6.c","path");
}



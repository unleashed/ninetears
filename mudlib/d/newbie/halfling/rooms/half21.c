#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"You are wandering deep within the northern reaches of the forest.  Dense vegetation "
"and huge trees dominate everywhere that this path has not been cut out at.  The "
"tree canopy breaks a little here, allowing you to catch a rare glimpse of blue sky "
"above you.  "
    "\n\n");

add_exit("south",ROOMS+"half18.c","path");
add_exit("east",ROOMS+"half22.c","path");


}

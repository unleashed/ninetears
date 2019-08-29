#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"The path makes almost a complete U-turn here.  Dense forest blocks all other "
"directions other than the path that you are on.  "
    "\n\n");

add_exit("south",ROOMS+"half11.c","path");
add_exit("southwest",ROOMS+"half10.c","path");
}



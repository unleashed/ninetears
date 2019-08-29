#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_short("Island of Maroek:  Forest Path\n");
set_long("Island of Maroek:  Forest Path\n\n"
"The trees are a bit more sparse, here.  There is a small stump to your south with "
"a simple shop's sign.  The forest around you seems full of life, as if nature is in perfect "
"balance throughout all of this island.  "
    "\n\n");

 add_clone(CHAR+"mean_cat.c",3);
add_clone(CHAR+"buzzard.c",1);
add_exit("west",ROOMS+"half2.c","path");
add_exit("north",ROOMS+"half9.c","path");
add_exit("south",ROOMS+"shop.c","door");
add_exit("east",ROOMS+"half4.c","path");
}



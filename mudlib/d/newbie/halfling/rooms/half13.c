#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"This section of the Maroek forest is much more overgrown than many others.  "
"Vines hang from every ancient tree, all of which tower high above you."
"  Judging from the looks of the tracks around the area and the refuse in the forest, "
"this must be Brownie central.  "
    "\n\n");

add_clone(CHAR+"brownie.c",6);
add_exit("northeast",ROOMS+"half17.c","path");
add_exit("southwest",ROOMS+"half7.c","path");
add_exit("south",ROOMS+"half8.c","path");
}



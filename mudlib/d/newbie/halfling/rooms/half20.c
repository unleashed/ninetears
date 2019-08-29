#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"You have come to a small clearing in the forest.  The grass is only up to your knees, "
"and you have a feeling of peace here.  Paths into the forest lay in several directions "
"from where you stand.  "
    "\n\n");

add_clone(CHAR+"sprite.c",4);
add_exit("west",ROOMS+"half19.c","path");
add_exit("south",ROOMS+"half17.c","path");
add_exit("northeast",ROOMS+"half24.c","path");
}



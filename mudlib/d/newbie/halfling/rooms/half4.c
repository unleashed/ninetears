#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"The large trees continue to form a canopy high above you, letting only enough light "
"filter through so that you aren't blinded by it.  There is a large tree to your south "
"which has an arc cut through it, leading to what appears to be a large cleared out "
"area.  "
    "\n\n");

add_clone(CHAR+"strag_human.c",1);
add_clone(CHAR+"murd_beggar.c",2);
add_exit("west",ROOMS+"half3.c","path");
add_exit("north",ROOMS+"half10.c","path");
add_exit("south",ROOMS+"square.c","path");
add_exit("east",ROOMS+"half5.c","path");
}



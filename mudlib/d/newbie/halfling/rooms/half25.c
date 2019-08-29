#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"Ahead, you can see a seemingly barren area of the island, with nothing but sand.  "
"To your south lies the relative safety of the forest, which you get the distinct feeling "
"you should be returning to.  "
    "\n\n");

add_clone(CHAR+"half_orc",2);
add_exit("south",ROOMS+"half22.c","path");
add_exit("north",ROOMS+"pit.c","path");
}



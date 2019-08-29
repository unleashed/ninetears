#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Forest\n");
set_long("Island of Maroek:  Forest Path\n\n"
"You have come to the foot of a temple which is placed right in the middle of the forest.  "
"The temple radiates feelings of happiness and peace throughout the area.  The doors "
"of the temple stand open, as if awaiting visitors to enter.  Dense forest prevents "
"any movement other than to the south.  "
    "\n\n");

add_item("temple","The temple is immense, yet the trees naturally hide it from almost "
"all directions.  The entrance has four huge columns and the whole structure seems to "
"be made of fine marble.  "
"\n");

add_clone(CHAR+"owl.c",2);
add_exit("southwest",ROOMS+"half20.c","path");
add_exit("north",ROOMS+"temple.c","door");
}



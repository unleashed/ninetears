#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
set_long("Island of Maroek:  Forest Path\n\n"
"You have arrived at the southeastern corner of the forest.  A well made path goes "
"to your south, and to your east, you see a building that bears a clerical symbol "
"upon it.  Oddly enough, it IS a building, and not in a tree or stump.  "
    "\n\n");

add_clone(CHAR+"mean_cat.c",1);
add_clone(CHAR+"bad_dog.c",1);
add_exit("west",ROOMS+"half4.c","path");
add_exit("north",ROOMS+"half11.c","path");
add_exit("south",ROOMS+"road.c","path");
add_exit("east",ROOMS+"raiseroom.c","door");
}



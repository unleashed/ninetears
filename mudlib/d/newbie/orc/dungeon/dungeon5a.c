#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Dungeon");
set_light(40);
set_long("\n\n"
   "hmm it's it's dark isn't it ?"
   "\n");
add_exit("door",DUNGEON +"dungeon2a","door");
}

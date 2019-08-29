//Ljen -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"


void setup(){
   set_short("Savannah");
   set_long("You are standing on the west side of the river, after crossing "
            "over the bridge. The savannah opens in all directions,"
	    " giving you a fantastic view over the small and big trees,"
            " the animals and the grass.\n");

    set_light(80);

    add_clone(NPC+"tiger.c", random(2) );

    add_exit("west" ,  SAVANNAH+"b4" ,   "path");
    add_exit("north",  SAVANNAH+"c3"  ,   "path");
    add_exit("east",   SAVANNAH+"d4"  ,   "path");
    add_exit("south",  SAVANNAH+"c5"  ,   "path");

}

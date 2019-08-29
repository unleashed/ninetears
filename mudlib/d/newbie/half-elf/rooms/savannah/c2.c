//Ljen nov -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"

void setup(){
   set_short("Savannah");
   set_long("Following the river to the north seems the best way to explore "
            "the big opening that the savannah is, that way if you get lost "
            "at least you will have water.\n");

    set_light(80);
    add_clone(NPC+"hyena.c");
 
    add_exit("north",       SAVANNAH+"c1"   ,   "path");
    add_exit("northeast",   SAVANNAH+"d1"   ,   "path");
    add_exit("south",       SAVANNAH+"c3"   ,   "path");

}

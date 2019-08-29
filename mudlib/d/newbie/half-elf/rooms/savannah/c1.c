// Ljen nov -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"


void setup(){
   set_short("Savannah");
   set_long("The river continues north, but there are a thick wall of"
	    " bushes here, so you can't get through it. You can follow the"
            " bushes east though, or turn back south.\n");

    set_light(80);

    add_item("bush", "Thick bushes, there is no way to go through.\n");


    add_clone(NPC+"lion.c",2 );

    add_exit("east",   SAVANNAH+"d1"  ,   "path");
    add_exit("south",  SAVANNAH+"c2"  ,   "path");

}

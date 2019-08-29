// Ljen nov -96
// Joram, 18 of September '96

inherit "/std/outside";
#include "path.h"


void setup(){
   set_short("Savannah");
   set_long("Going to the east the savannah opens in all its magnificence "
            "the tall trees are the unique big vegetal life you can see around"
            ", forming the very core of the ecosystem.  Although the grass that "
            "grows in here is the principal place where the vital circle starts, "
            "this is not visible to you and it dims when looking at the great "
            "predators and herbivorous animals.\n");

    set_light(80);

    add_clone(NPC+"tiger.c", random(2) );
    add_clone(NPC+"hyena.c", random(2));

    add_exit("west",   SAVANNAH+"e4"  ,   "path");
    add_exit("south",  SAVANNAH+"f5"  ,   "path");

}

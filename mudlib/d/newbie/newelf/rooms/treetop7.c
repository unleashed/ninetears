#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      "\nYou have arrived deep within the treetops area. You are re"
      "laxed, and you have no fears to worry about as of yet. "
      "The aromas rising from the trees and greenery create an "
      "alluring scent."
      "The scents tickle your nose and make you feel better about "
      "the world around you."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"treetop12.c","path");
    add_exit("west",ROOMS+"treetop3.c","path");
}


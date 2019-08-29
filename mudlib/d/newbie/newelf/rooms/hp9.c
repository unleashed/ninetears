#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      "  This part of the forest is inhabited with the evil tree imps. "
      "You feel their eyes upon your possesions."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("north",ROOMS+"hp10.c","hidden");
    add_exit("northwest",ROOMS+"hp8.c","hidden");
    add_clone(CHAR+"wood_imp.c",3);
}


#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " The leaves here have a silky finish on the top side. It "
      "is used to keep water within the leaves. You find this a marvelous "
      "concept and start making plans for the future."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"treetop2.c","path");
}


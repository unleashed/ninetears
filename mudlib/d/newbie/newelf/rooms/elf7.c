#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "This forest, just like most forests would, has trees growing in "
      "it, but these are larger than most normal trees. They seem"
      " to grow exceptionally large in the leven homelands."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"elf12.c","path");
    add_exit("west",ROOMS+"elf3.c","path");
    add_clone(CHAR+"forlarren.c",3);
    add_clone(CHAR+"rabbit.c",1);
}


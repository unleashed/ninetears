#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " It seems you have stumbled upon a dead end. Oh well, you "
      "can always just retrace your steps."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"tavern.c","hidden");
    add_exit("west",ROOMS+"elf9.c","path");
    add_clone(CHAR+"deer.c",1);
    add_clone(CHAR+"rabbit.c",1);
    add_clone(CHAR+"forlarren.c",1);
}


#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "You enter into the forest through a small path between two "
      "trees. You find yourself in a peaceful and beautiful area. "
      "You look around and see that there is very little elven life "
      "but much more animal life."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("north",ROOMS+"elf2.c","path");
    add_exit("northeast",ROOMS+"elf3.c","path");
    add_exit("south",ROOMS+"raiseroom.c","path");
    add_clone(CHAR+"rabbit.c",2);
}



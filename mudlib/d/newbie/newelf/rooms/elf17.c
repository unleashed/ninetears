#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " The path is again mostly invisible due to the return of "
      "normal lighting conditions in this area. You bend over and start"
      " to pluck one of the flowers, but think better of yourself, with "
      "how much your Grandparents told you about how at one time, almost all th"
      "e flowers disappeared from the forest. Then again, your grand"
      "parents still believe that the drow and elves can come back "
      "to the world of light without causing any major damage."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northeast",ROOMS+"elf13.c","path");
    add_exit("southwest",ROOMS+"faeyn1.c","path");
    add_exit("southeast",ROOMS+"Eldar1.c","path");
    add_clone(CHAR+"boar.c",1);
    add_clone(CHAR+"rabbit.c",1);
    add_clone(CHAR+"deer.c",1);
    add_clone(CHAR+"frog.c",1);
    add_clone(CHAR+"sprite.c",1);
    add_clone(CHAR+"squirrel.c",1);
}


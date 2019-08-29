#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " You are deep within the forest. The birds are singing, and there "
      "are many animals roaming around. The plantlife flourishes in "
      "this area, and you can see a small, clear stream running through "
      "the undergrowth."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"elf4.c","path");
    add_exit("southeast",ROOMS+"elf9.c","path");
    add_exit("up",ROOMS+"treetop11.c","hidden");
    add_clone(NPCS+"old_man.c",1);
}


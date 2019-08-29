#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      "  You notice the sounds getting further away, but there are other"
      " sounds that seem to be getting closer. Well not really closer "
      "but more like 'reappearing'. To be more precise, the forest sounds are returning "
      "to the area. It seems that now the forest in this area is again "
      "at peace. But for some reason there is still unease in the forest "
      "that you didn't feel before because you were so at peace in the "
      "forest. "
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_clone(CHAR+"Ghawk.c", 1);

    add_exit("west",ROOMS+"treetop9.c","path");
}


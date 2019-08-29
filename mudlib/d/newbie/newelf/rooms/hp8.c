#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      " There is a sense of evil coming almost directly from your north. The evil "
      "is pounding your senses as if you could see it, hear it, smell it even."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"hp9.c","hidden");
    add_exit("northwest",ROOMS+"hp7.c","hidden");
    add_clone(CHAR+"wood_imp.c",3);
}


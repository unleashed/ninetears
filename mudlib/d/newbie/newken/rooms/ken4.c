#include "path.h"

inherit ROOMS+"gen.c";
void setup(){my_setup();
    set_short("Highlo : Forest Hill  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Forest Hill.  \n\n"
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_exit("west",ROOMS+"ken2.c","path");
    add_exit("northeast",ROOMS+"ken13.c","path");
    add_exit("southeast",ROOMS+"ken17.c","path");
}



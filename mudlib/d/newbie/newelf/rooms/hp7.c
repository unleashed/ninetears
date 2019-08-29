#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      " You can feel the presence you are searching for closer now. "
      "Everything causing all this evil must be waiting for her strength"
      " to rebuild. You feel the massive power building up even from here."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"hp8.c","hidden");
    add_exit("northeast",ROOMS+"hp6.c","hidden");
    add_clone(CHAR+"wood_imp.c",2);
add_clone(CHAR+"spider.c",1);
}


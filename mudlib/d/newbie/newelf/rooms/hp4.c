#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      " You feel pain begining in your head from the evil that is "
      "seeping from everything around you. You hope this pain will"
      " go away soon."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"hp3.c","hidden");
    add_exit("northwest",ROOMS+"hp5.c","hidden");
    add_clone(CHAR+"wood_imp.c",1);
    add_clone(CHAR+"spider.c",2);
}


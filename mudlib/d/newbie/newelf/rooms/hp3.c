#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      "The evil seems to be growing stronger as you get closer to your destination."
      " You are starting to wonder what the problem in this area is."
      " And you also wonder what is causing all the evil to seep into the forest."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"hp2.c","hidden");
    add_exit("north",ROOMS+"hp4.c","hidden");
    add_clone(CHAR+"wood_imp.c",1);
    add_clone(CHAR+"spider.c",2);
}


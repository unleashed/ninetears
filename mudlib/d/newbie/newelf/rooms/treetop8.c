#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      "The sounds of voices, people bustling, and just general movement "
      "float up from beneath you, and you can tell that there is a "
      "large center of activity somewhere close by. When you take a "
      "breath of 'fresh' air, then you actually get a lungful of smoke."
      " You begin to wonder what all the business is about."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"treetop3.c","path");
    add_exit("southeast",ROOMS+"treetop13.c","path");
}


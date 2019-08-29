#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " The leaves beneath you suddenly become dense and seem to "
      "be able to support a lot more weight than average areas. "
      "You look down to try and see the forest floor beneath you "
      "and are not able to see the ground. But it matters not to "
      "an elves sense of direction, especially since it works without having to see the ground."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"treetop14.c","path");
}


#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " This area of the treetops has a rougher, and weaker terrain. "
      "It would be almost perilous to cross this area for anyone who "
      "isnt an extremely skilled treewalker. There are holes in the "
      "path from where the branches beneath you have rotted and fallen "
      "off. You begin to wonder if you are skilled enough to cross this"
      " area."
      "\n\n");
    add_clone("/d/newbie/newelf/chars/Ghawk.c", 1);


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"treetop14.c","path");
}


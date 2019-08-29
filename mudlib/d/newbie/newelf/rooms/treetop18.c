#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " You climb the tree and find yourself facing an old elf. "
      "He is a mystery to most of the other elves, the only thing they "
      "know about him is that he used to teach elves to treewalk, that "
      "is until they started teaching the young themselves. Now he "
      "lives here by himself, more or less nothing more than an old hermit "
      "now."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_clone(CHAR+"treewalker.c",1);

    add_exit("down",ROOMS+"elf18.c","hidden");
}


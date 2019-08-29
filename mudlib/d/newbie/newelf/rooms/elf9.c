#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "  This whole forest, all part of your legacy. Everything here "
      "belongs to your family. But seeing as all elves are closely "
      "related, then that is no big thing."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"elf11","path");
    add_exit("south",ROOMS+"elf6.c","path");
    add_exit("east",ROOMS+"elf10.c","path");
    add_clone(CHAR+"deer.c",1);
    add_clone(NPCS+"elf_kid.c",1);
}


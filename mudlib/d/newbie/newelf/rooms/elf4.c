#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "This is a forest glade. There is a small pond in the middle "
      "of it where animals come to drink. You have heard stories about this "
      "pond. Mostly how someone would fall in, or even go swimming in it, "
      "but they would never again emerge. It seems that if they died in "
      "there, than there would be corpses all around here, so you wonder "
      "what this pond really is."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"elf2.c","path");
    add_exit("northeast",ROOMS+"elf11.c","path");
    add_clone(CHAR+"deer.c",1);
}


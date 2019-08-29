#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " The forrest appeals to you just to lie down and take a "
      "nap. The peace in the area almost convinces you to just "
      "drop everything and and relax, but the chance of wasting "
      "your life away laying in the forest frightens it out of "
      "you.\n You think to yourself 'There are just too many things "
      "to do and see, I can't just forget it...'"
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"elf7.c","path");
    add_clone(CHAR+"frog.c",2);
    add_clone(CHAR+"rabbit.c",1);
    add_clone(CHAR+"forlarren.c",1);
}


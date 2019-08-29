#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " You gracefully step over some branches that have fallen out "
      "of the old trees that inhabit this area. You look at the trees "
      "and realize that they are hundreds or maybe even thousands of "
      "years older than you are. You are awed at the immensive size and "
      "stature of these trees, and wonder how people would want to cut "
      "down trees and then let them rot, like you have heard in many "
      "stories about the outside world."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southeast",ROOMS+"elf14.c","path");
    add_clone(CHAR+"sprite.c",1);
}


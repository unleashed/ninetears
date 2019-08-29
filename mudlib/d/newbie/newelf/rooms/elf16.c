#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " This part of the forest is dimmer than most. You look up to see "
      "that the leaves are blocking out much of your sunlight. The path through here "
      "is extremely easy to see, as the smallest plants have died from so much "
      "lack of sunlight. The path, now that you have an unobscured "
      "view of it, is not really a dirt path as you first thought. "
      "Now that you can see it, you can tell that at one time this "
      "was a gravel road."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"elf14.c","path");
    add_clone(CHAR+"squirrel.c",2);
    add_clone(CHAR+"rabbit.c",1);
}


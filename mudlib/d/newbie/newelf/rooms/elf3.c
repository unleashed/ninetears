#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "You are getting deep into the forest. There seem to be odd animals "
      "and new plant life. When you look around you see a pattern in the "
      "trees."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_item("pattern","\nThe pattern in the trees kind of resemble a "
      "stairway.");
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"elf1.c","path");
    add_exit("northeast",ROOMS+"elf6.c","path");
    add_exit("east",ROOMS+"elf7.c","path");
    add_exit("southeast",ROOMS+"elf8.c","path");
    add_exit("up",ROOMS+"treetop3.c","hidden");
    add_clone(CHAR+"deer.c",2);
    add_clone(CHAR+"forlarren.c",1);
}



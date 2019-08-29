#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      "  The animals here seem peaceful enough, they probably wouldn't "
      "even be a good fight. But you dont even feel much like fighting."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"treetop1.c","path");
    add_exit("northeast",ROOMS+"treetop6.c","path");
    add_exit("east",ROOMS+"treetop7.c","path");
    add_exit("southeast",ROOMS+"treetop8.c","path");
    add_exit("down",ROOMS+"elf3.c","hidden");
    add_clone(NPCS+"birdie.c", 4);
    add_clone(NPCS+"spider.c", 1);
}



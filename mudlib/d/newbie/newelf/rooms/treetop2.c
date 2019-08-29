#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("\nTreetops \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("\nYou feel tranquil walking among the treetops. "
      "In the old stories, this is what was referred to as the "
      "'Safe Haven' of the elves. Not even the evil drow could "
      "reach them in their treetops.\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"treetop1.c","path");
    add_exit("north",ROOMS+"treetop4.c","path");
    add_exit("northwest",ROOMS+"treetop5.c","path");
    add_clone(CHAR+"birdie.c",1);
    add_clone(CHAR+"hawk.c",1);
    add_clone(CHAR+"spider.c",1);
}



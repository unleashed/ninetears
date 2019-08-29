#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops\n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("\nYou stand upon the treetops, from here you can see "
      "Aaroc, the elven town. Your view expands to the horizon in all "
      "directions. The beauty of this overwhelms you and pride fills your heart.\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_clone(CHAR+"birdie.c",2);
    add_clone(CHAR+"spider.c",1);

    add_exit("north",ROOMS+"treetop2.c","path");
    add_exit("northeast",ROOMS+"treetop3.c","path");
}



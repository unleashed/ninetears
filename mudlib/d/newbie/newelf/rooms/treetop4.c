#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("\nYou look down and see through the abundant leaves "
      "and see a bunch of nests below in the branches. You can also "
      "see where there are new bunches of buds growing for the next "
      "seasons leafing.\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"treetop2.c","path");
    add_exit("northeast",ROOMS+"treetop11.c","path");
}


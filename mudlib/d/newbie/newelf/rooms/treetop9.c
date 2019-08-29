#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("\nThe forest is quieter here, but the smoke is still in the air."
      " All the plant life seems to be slightly hindered in the smokey "
      "area. Unfortunately there is nothing you can do about it but let it pass."
      " Oh well, maybe some day, the world will be a lot better, but"
      " that is the future, not now, right???\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"treetop11.c","path");
    add_exit("south",ROOMS+"treetop6.c","path");
    add_exit("east",ROOMS+"treetop10.c","path");
}


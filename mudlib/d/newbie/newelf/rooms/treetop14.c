#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " When you walk into the area, you notice that the leaves beneath "
      "your feet become broader and flatter. The leaves are also a lighter"
      " green than before. You understand immediately that you are standing "
      "directly above the glade of trees that Edgar the Innkeeper "
      "planted. There was a time before when this area was indis"
      "tinguishable from any other part of the forest. But now the "
      "leaves are a sure sign as to where you are at."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"treetop13.c","path");
    add_exit("northwest",ROOMS+"treetop15.c","path");
    add_exit("northeast",ROOMS+"treetop16.c","path");
}


#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " You feel peace and comfort emanating from all around you. "
      "Down below you hear the sound of someone snoring in a peace"
      "ful slumber. You start walking on to....Wait!? Snoring? Who"
      " in their right mind would be asleep in the middle of the f"
      "orest???"
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"treetop7.c","path");
}


#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops \n\n"
      "  Leaves, vines, branches, animals, everything from a forested "
      "that you would expect from a forest surrounds on all sides. "
      "The beauty surrounds you and envelopes you in a feeling of security."
      " But again the feeling of unease seeps into your thoughts. "
      "It is starting to annoy you, but it is still to far away for "
      "you to locate with your forestry skills. Maybe some day soon you"
      " will find it's source and destroy it.\n\n");


add_item(({"tree","trees","forest"}),TREE);
add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
add_feel(({"ground","dirt","floor"}),GROUND);

add_exit("southwest",ROOMS+"treetop4.c","path");
add_exit("southeast",ROOMS+"treetop9.c","path");
add_exit("down",ROOMS+"elf11.c","hidden");
add_clone(NPCS+"old_woman.c",1);
}


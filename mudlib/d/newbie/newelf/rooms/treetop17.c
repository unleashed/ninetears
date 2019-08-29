#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
      " From beneath the canopy of leaves you begin to smell the "
      "scent of wildflowers. It is a sickly sweet smell, but also "
      "pleasant. You wonder if there are any flowers down there you could pick, "
      "and give to your families."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northeast",ROOMS+"treetop13.c","path");
}


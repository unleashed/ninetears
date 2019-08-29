#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("\nYou can feel the leaves below you, and they are "
      "soft, and comforting to the feet. You are glad for any relief, no matter how small "
      "since you know that your future holds many perils and dangers "
      "that will confront you.\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("north",ROOMS+"treetop9.c","path");
    add_exit("southwest",ROOMS+"treetop3.c","path");
}


#include "path.h"

inherit "/std/room";
void setup()
{
    set_short("Eldar's Home.  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Eldar's Home.  \n\n"
      "  You stand within the eldar's house. It is small"
      " and quiet. The noise of the forest doesn't penetrate"
      " through the walls of his house so it is real peaceful. "
      "You look around and realise that the eldar is not here."
      " Oddly enough, his entire house is empty and abandoned."
      " The room has an echo that is present anywhere that is "
      "widely unused."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("southwest",ROOMS+"Eldev.c","path");
    add_exit("northwest",ROOMS+"elf17.c","path");
}


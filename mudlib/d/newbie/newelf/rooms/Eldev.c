#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " This is a small clearing within the forest that has been "
      "claimed by the famed smith Eldevan. He lives here, but any"
      " elf who still wishes to live, would not live within the forest itself."
      " He claimed this area so he would be alone, and he has withdrawn"
      " from elven society. This is all from when his wife 'Shirein'"
      " died."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"faeyn1.c","path");
    add_exit("northeast",ROOMS+"Eldar1.c","path");
    add_exit("west",ROOMS+"elf18.c","path");
    add_clone(CHAR+"smith.c",1);
}



#include "path.h"


inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " You walk into the living area of Faeyn the Treant. It is "
      "quiet, but not solemn. Faeyn stands in the center of the "
      "clearing, without moving or saying a word. He seems to look "
      "older, but he appears to be just as strong. You look down and "
      "realize that the grass here is a darker green than it is "
      "anywhere else. You look around at all the plantlife in the "
      "area and are unsurprised to see that all the plants here "
      "seem darker, and more healthier.\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northeast",ROOMS+"elf17.c","path");
    add_exit("southeast",ROOMS+"Eldev.c","path");
    add_clone(NPCS+"faeyn.c",1);
}


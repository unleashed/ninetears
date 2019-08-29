#include "path.h"

inherit ROOMS+"gen.c";
void setup(){my_setup();
    set_short("Highlo : Forest Hill  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Forest Hill.  \n\n"
      "  This is a small clearing in the town of Highlo, "
      "where kender camp from time to time. There is a "
      "fire burning cheerfully here, that an old kender is tending at the moment. "
      " He smiles as you approach, and looks at you "
      "curiously."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_exit("west",ROOMS+"center.c","path");
}



#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      " Silence floats around you as you walk into the room. Not "
      "utter silence, but the peaceful silence. The wind whispering in the trees, "
      "animals moving about, the trickling sound of a small water"
      "fall. All the things you have come to expect of your home"
      "lands."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);
    add_item(({"water","waterfall"}),"\nThe waterfall is gonna be descr"
      "ibed how Aisling wants it, so she had better think of something good.:)");

    add_exit("northwest",ROOMS+"elf8.c","path");
    add_exit("northeast",ROOMS+"elf14.c","path");
    add_exit("southwest",ROOMS+"elf17.c","path");
    add_clone(CHAR+"sprite.c",1);
    add_clone(CHAR+"deer.c",1);
    add_clone(CHAR+"boar.c",1);
}


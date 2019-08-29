#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("The Elven Forest  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("The Elven Forest.  \n\n"
      "  Scents of flowers and greenery drift to you as you walk through the forest."
      " It is a beautiful place and you remember all sorts "
      "of things from your childhood in this forest that brings "
      "a smile to your face. Why even in this area sitting on an "
      "old treestump was where you recieved your first kiss."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"elf3.c","path");
    add_exit("south",ROOMS+"storeroom.c","hidden");
    add_exit("southeast",ROOMS+"elf13.c","path");
    add_clone(CHAR+"squirrel.c",1);
    add_clone(CHAR+"rabbit.c",2);
}


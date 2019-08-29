#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      "You ack.\n"
      "For some unknown reason you start growling at the imp.\n"
      "This forest is darker than your normal everyday fores area. "
      "You can feel evil emanating from the trees and grass. You feel"
      " really unwelcome in this area."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("south",ROOMS+"hp1.c","hidden");
    add_exit("north",ROOMS+"hp3.c","hidden");
    add_clone(CHAR+"wood_imp.c",1);
    add_clone(CHAR+"spider.c",2);
}


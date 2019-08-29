#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      "You begin to tremble at the tremendous pressure of the evil "
      "pressing upon your mind. You know that somehow you have to stop the "
      "evil burning these woods. It presses upon your concience that the so"
      "meone who is in these woods is trying to take over more than just "
      "this measly small area. You feel that she is trying to take over the"
      " elves homelands. "
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("east",ROOMS+"hp5.c","hidden");
    add_exit("southwest",ROOMS+"hp7.c","hidden");
    add_clone(CHAR+"wood_imp.c",2);
    add_clone(CHAR+"spider.c",1);
}


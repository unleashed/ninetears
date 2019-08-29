#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Hidden Path");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Hidden Path. \n\n"
      " The pain in your head is steadily growing as you move further "
      "and further into this evil wood. You realize that the pain is "
      "not yours but what the forest is feeling from all the evil within it."
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("west",ROOMS+"hp6.c","hidden");
    add_exit("southeast",ROOMS+"hp4.c","hidden");
    add_clone(CHAR+"wood_imp.c",2);
    add_clone(CHAR+"spider.c",1);
}


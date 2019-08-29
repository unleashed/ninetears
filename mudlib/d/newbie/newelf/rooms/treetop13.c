#include "path.h"

inherit "/std/outside";
void setup()
{
    set_short("Treetops  \n");
    set_light(LIGHT);
    add_property("no_undead",1);
    set_long("Treetops.  \n\n"
" You walk across the leaves of the trees and enter this beautiful"
"and serene area. Beneath you, you hear the sound of water running rapidly "
"over a rocky basin. The room is silent with just enough "
"noise not to be too silent. Birds singing and playing above the "
"trees, "
      "\n\n");


    add_item(({"tree","trees","forest"}),TREE);
    add_sound(({"birds","wildlife","bird","songs"}),BIRDS);
    add_feel(({"ground","dirt","floor"}),GROUND);

    add_exit("northwest",ROOMS+"treetop8.c","path");
    add_exit("northeast",ROOMS+"treetop14.c","path");
    add_exit("southwest",ROOMS+"treetop17.c","path");
}


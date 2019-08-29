#include "path.h"
inherit "/std/outside";

void setup()
{
add_property("no_undead",1);
set_light(LIGHT);
set_short("Island of Maroek:  Western Beach\n");
set_long("Island of Maroek:  Western Beach\n\n"
"You have arrived on the western-most beach of Maroek.  Waves crash against the shore "
"and you can feel the sun beating down on you from above.  The sand is a dull brown "
"and fins can be seen among the waves off shore."
    "\n\n");

add_item(({"fins","sharks","fish"}),"The fins are definately from man-eaters, thus "
"discouraging you from taking a quick dip.  Not that you ever learned "
"to swim, anyway.\n");

add_feel("sand","The sand is warm and gritty to the touch.\n");

add_clone("pippin.c",1);
add_exit("east",ROOMS+"half1.c","path");
}



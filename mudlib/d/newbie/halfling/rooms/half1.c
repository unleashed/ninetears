#include "path.h"

inherit "/std/outside";
void setup()
{
set_short("Island of Maroek:  Forest Path\n");
set_light(LIGHT);
set_short("Island of Maroek:  The Forest");
add_property("no_undead",1);
set_long("Island of Maroek:  Forest Path\n\n"
"The trees here are ovegrown and shade out the area with their shadows.  "
"Far to the north you can see a small mountain, and to your west, you hear the crashing "
"of waves.  A line of buildings has formed along this road with its meager commerce.  "
    "\n\n");

add_item(({"trees","shadows"}),"These trees are more ancient than even the oldest and "
"wisest of halflings can remember.  Their bases are often used as homes for your fellow "
"halflings.\n");
add_sound(({"waves","crashing","ocean"}),"You can hear the faint sound of waves crashing "
"against a beach to your west.\n");

add_clone(CHAR+"mean_cat.c",2);
add_exit("west",ROOMS+"half26.c","path");
add_exit("east",ROOMS+"half2.c","path");
add_exit("north",ROOMS+"half7.c","path");
add_exit("northeast",ROOMS+"half8.c","path");
}



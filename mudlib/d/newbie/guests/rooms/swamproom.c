#include "path.h"
inherit "/std/outside.c";
int done = 0;

setup(){
set_light(40);
set_zone("highway");
if (!done)
{
//add_clone(GENCHARS+SWAMPCHARS[random(sizeof(SWAMPCHARS))],random(2));

//add_clone(GENCHARS+SWAMPCHARS[random(sizeof(SWAMPCHARS))],random(4));
done=1;
}
}

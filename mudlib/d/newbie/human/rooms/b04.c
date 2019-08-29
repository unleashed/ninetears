#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   Shells are spread out on most of this part of the beach and you "
    "can't avoid standing on them, making loud, scrunching noises as you "
    "move. They are particularly thick nearer to the trees lining the beach, "
    "which seems a little odd as it is quite a way above the high-water "
    "line. "
    "\n\n");
    add_item("shells","Shells of all sizes, colors and shapes, broken as well "
    "as whole. They seem to have been deliberately put here as an early "
    "warning device by someone. \n");
    add_item(({"tree","trees"}),"The trees of the nearby jungle are very tall "
    "and grow closely together. There is the beginning af a trail through them "
    "here. \n");
}
void init()
{
    add_exit("north",HAVMAND+"b03.c","path");
    add_exit("south",HAVMAND+"b05.c","path");
    add_exit("west",HAVMAND+"p05.c","path");

    ::init();
}

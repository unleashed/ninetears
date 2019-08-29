#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   The long white sandy beach stretches north and south. It is a little "
    "odd that there appears to be more shells on this part of the beach "
    "than anywhere else. They certainly make a lot of noise as you crunch "
    "your way over them, and if anything was listening they would have plenty "
    "of time to notice you."
    "\n\n");
    add_item(({"shell","shells"}),"Piles of shells of all shapes, sizes and "
    "colors, they certainly couldn't have arranged themselves like that "
    "naturally. You can't avoid walking on them and "
     "it appears that someone has gone to a lot of effort to get "
    "advance warning of anyone approaching. You had better be prepared.\n");

}
void init()
{
    add_exit("north",HAVMAND+"b01.c","path");
    add_exit("south",HAVMAND+"b03.c","path");
    add_exit("west",HAVMAND+"p01.c","path");


    ::init();
}


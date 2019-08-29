#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "This is a very dull bit of jungle with not a lot to see except the "
    "trees. You consider picking up some of the fallen leaves, but there "
    "is no one to throw them at and they look to be too damp anyway. "
    "\n\n");
    add_item("leaves","Piles of fallen leaves are clumped together at the "
    "base of the trees. They look to be very damp. "
    "\n");

}
void init()
{
    add_exit("north",HAVMAND+"j06.c","path");
    add_exit("south",HAVMAND+"j09.c","path");
    add_exit("east",HAVMAND+"j08.c","path");
    add_exit("west",HAVMAND+"t04.c","path");

    ::init();
}



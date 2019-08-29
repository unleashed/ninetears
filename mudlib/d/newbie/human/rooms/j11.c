#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "Near the edge of the jungle the trees don't seem to grow as close "
    "together as they do further in. It is possible to still see the track "
    "to the west, but mainly all you see is trees. A sudden movement high "
    "up catches your eye, but when you look you can't see anything there. "
    "\n\n");
    add_item("track","From here it looks like a dirt track which has seen "
    "a lot of use. "
    "\n");
}
void init()
{
    add_exit("west",HAVMAND+"t06.c","path");
    add_exit("east",HAVMAND+"j12.c","path");
    add_exit("north",HAVMAND+"j09.c","path");
    add_exit("south",HAVMAND+"j13.c","path");

    ::init();
}



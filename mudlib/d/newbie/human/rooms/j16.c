#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You are deep in the jungle. It wouldn't be so bad, but every now and "
    "then you catch flashes of movement between the trees. Not enough to be "
    "able to see what is causing them, but enough to make you worry. "
    "Perhaps this is not a good place to hang around for long. "
    "\n\n");

}
void init()
{
    add_exit("north",HAVMAND+"j23.c","path");
    add_exit("south",HAVMAND+"j30.c","path");
    add_exit("west",HAVMAND+"j10.c","path");
    add_exit("east",HAVMAND+"p02.c","path");

    ::init();
}



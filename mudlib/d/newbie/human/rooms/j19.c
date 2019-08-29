#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The jungle is so dense to the north and west that there is no way you "
    "could ever hack your way through in those directions. An interesting "
    "fungus is growing from the base of one of the trees here, but otherwise "
    "it just looks pretty much the same as the rest of the trees. "
    "\n\n");
    add_item("fungus","A nasty poisonous looking toadstool, it looks like "
    "the sort of thing little people in fairy stories always use for houses. "
    "It has a red cap with white spots on, but you decide to leave it alone. "
    "\n");

}
void init()
{
    add_exit("south",HAVMAND+"p02.c","path");
    add_exit("east",HAVMAND+"j20.c","path");

    ::init();
}



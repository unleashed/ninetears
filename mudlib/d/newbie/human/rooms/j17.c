#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You have no idea why you came here, because there is nowhere to go "
    "except where you came from. The jungle is just too thick here to hack "
    "your way through. "
    "\n\n");

}
void init()
{
    add_exit("east",HAVMAND+"b01.c","path");

    ::init();
}



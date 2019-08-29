#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "There are less trees here, but still enough to make travelling difficult. "
    "It is lucky that there is a well defined track to follow, even though "
    "the path itself is getting steeper as it heads downward. "
    "\n\n");


}
void init()
{
    add_exit("west",HAVMAND+"j33.c","path");
    add_exit("northeast",HAVMAND+"j35.c","path");

    ::init();
}



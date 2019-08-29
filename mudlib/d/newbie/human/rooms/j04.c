#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You climb onto a fallen log here to see if you can get a better view "
    "of anything, but still all you can see are trees and more trees. There "
    "is so much vegetation to the east that it forms an impenetrable barrier, "
    "in other words, there is no way you will ever get through that way. "
    "The paths to the north, south and west look reasonably open though. "
    "\n\n");
    add_item("log","One of the huge trees has fallen over here, completely "
    "covering the path. When you look closely you can see that the bottom "
    "of the trunk has rotted through. "
    "\n");

}
void init()
{
    add_exit("north",HAVMAND+"j01.c","path");
    add_exit("south",HAVMAND+"j05.c","path");
    add_exit("west",HAVMAND+"j03.c","path");

    ::init();
}



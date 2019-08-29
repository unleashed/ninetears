#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The trees seem to be growing closer together than ever just here. There "
    "is no way you will be able to force your way through and the only ways "
    " you can go are back west or northwest. "
    "\n\n");

}
void init()
{
    add_exit("west",HAVMAND+"j07.c","path");
    add_exit("northwest",HAVMAND+"j06.c","path");

    ::init();
}



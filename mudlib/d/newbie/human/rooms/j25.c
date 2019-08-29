#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The track is definately starting to slope upwards to the northeast, "
    "although everything else is still the same. Still plenty of trees "
    "around, with moss and lichen covering their trunks, but something "
    "seems different. You just wish you knew what it was. "
    "\n\n");

}
void init()
{
    add_exit("northeast",HAVMAND+"j26.c","path");
    add_exit("south",HAVMAND+"j24.c","path");

    ::init();
}



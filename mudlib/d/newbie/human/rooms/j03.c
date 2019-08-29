#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "This part of the jungle doesn't seem to be so hot and humid. The trees "
    "still crowd around you, but you can feel a soft breeze coming from "
    "somewhere. Maybe its from the beach you can see to the north. "
    "\n\n");
    add_feel("breeze","There is a gentle breeze blowing from the sea, making "
    "you feel a lot cooler and refreshed. "
    "\n");

}
void init()
{
    add_exit("west",HAVMAND+"j02.c","path");
    add_exit("east",HAVMAND+"j04.c","path");
    add_exit("north",HAVMAND+"b07.c","path");

    ::init();
}



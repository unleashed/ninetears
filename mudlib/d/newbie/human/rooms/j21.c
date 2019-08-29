#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The trees are very thick here and the only way out is the way you came "
    "in. There is no way you could hack another path out. There is a fallen "
    "log here, but it is too heavy to move, even if you wanted to. "
    "\n\n");
    add_item("log","A rotten branch has fallen from a tree and landed here. "
    "It is so rotten that when you touch it, it crumbles in your fingers. "
    "\n");

}
void init()
{
    add_exit("east",HAVMAND+"j22.c","path");

    ::init();
}



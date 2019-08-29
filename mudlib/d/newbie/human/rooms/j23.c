#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The trees stand closely together, there trunks almost touching. Apart from the "
    "path north and south, there is no way you could ever cut your way out of "
    "here. High above you is a nest of some sort, and you can hear "
    "rustling noises all around, but even when you climb onto a fallen "
    "branch you still can't see anything significant. "
    "\n\n");
    add_item("nest","This is a nest of some sort of bird. It is made from lose "
    "twigs and bits of moss. It is high enough to discourage any predators. "
    "\n");
    add_item("branch","This is a branch that has fallen from one of the "
    "trees at some time. It has partially rotted away, but if you are "
    "careful, you can climb onto it without hurting yourself."
    "\n");

}
void init()
{
    add_exit("south",HAVMAND+"j16.c","path");
    add_exit("northwest",HAVMAND+"j24.c","path");


    ::init();
}



#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The track steepens sharply and narrows here.\n"
    "You find that you are working your way along between a couple of "
    "large fallen trees which form a sort of ladder here. The vines "
    "which in life spiraled around the tree trunks make good hand holds "
    "as you scramble along the track. "
    "\n\n");
    add_item("vines",
    "The vines around the fallen tree trunk are as thick as your wrist "
    "and very fibrous, you try to pull one loose but it's firmly anchored "
    "to the trunk. "
    "\n");
    add_item(({"trees","fallen trees","tree trunks"}),"The fallen tree trunks "
    "are firmly embedded into the packed earth of the jungle floor. "
    "\n");

add_item("ladder","These vines form a make-shift ladder, allowing you to climb "
"across the small ravine here.  \n");
add_item("ravine","This small indentation in the ground could be dangerous to your "
"health, if you fell in.  You decide it's best to stay away from it.  \n");
}
void init()
{
    add_exit("west",HAVMAND+"j26.c","path");
    add_exit("southeast",HAVMAND+"j28.c","path");

    ::init();
}




#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "As you walk along this track, you find yourself wondering how it can be "
    "so dry and dusty when the jungle nearby is obviously damp and moist. "
    "Whatever causes it, you notice little clouds of dust forming whenever "
    "you take a step.\n"
    "The track continues north and south, and there looks to be a small shop "
    "to the west. The inevitable jungle is to the east. "
    "\n\n");
    add_item("dust","Small puffs of dust form when you take a step along "
    "the track.\n");

    add_exit("north",HAVMAND+"t03.c","path");
    add_exit("south",HAVMAND+"t05.c","path");
    add_exit("west",HAVMAND+"v02.c","path");
    add_exit("east",HAVMAND+"j07.c","path");
}

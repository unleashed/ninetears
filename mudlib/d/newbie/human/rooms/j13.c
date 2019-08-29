#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You are not far from the village and already it is getting more difficult "
    "to force your way through the trees. Branches keep flicking back into "
    "face, making it more difficult to move quickly. "
    "\n\n");
    add_item( ({"branch","branches"}),"Some of the lower branches seem very "
    "pliable, and they tend to swing back and hit you after you have passed. "
    "\n");

}
void init()
{
    add_exit("west",HAVMAND+"t07.c","path");
    add_exit("north",HAVMAND+"j11.c","path");
    add_exit("south",HAVMAND+"j14.c","path");
    add_exit("northeast",HAVMAND+"j12.c","path");

    ::init();
}



#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You are climbing an upward spiralling track through the jungle, although "
    "it doesn't seem to be very steep at this point. There are plenty of "
    "trees here, and you keep hearing rustling noises in the leaf-litter. "
    "\n\n");
    add_sound("rustling","You really, really hope its the sounds of birds"
    "you can hear scrummaging through the leaves. "
    "\n");
    add_item("leaf-litter","Piles of fallen leaves make excellent homes for "
    "various bugs and crawly things. "
    "\n");

}
void init()
{
    add_exit("east",HAVMAND+"j27.c","path");
    add_exit("southwest",HAVMAND+"j25.c","path");

    ::init();
}



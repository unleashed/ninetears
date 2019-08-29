#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "This is a very thick patch of the jungle. There is no way you would "
    "ever be able to force your way through any of it except to the west "
    "or southwest. When you look up, however, you can see a nest high in "
    "the branches of one of the trees. "
    "\n\n");
    add_item("nest","This is the nest of one of the many birds you sometimes "
    "hear as you wander through the forest. It is made from small twigs and "
    "anything else its owner could find, and is high enough to keep most "
    "predators out. "
    "\n");

}
void init()
{
    add_exit("west",HAVMAND+"j11.c","path");
    add_exit("southwest",HAVMAND+"j13.c","path");

    ::init();
}



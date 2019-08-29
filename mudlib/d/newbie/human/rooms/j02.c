
#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "This looks like another dead end. The trees are thinner here, allowing "
    "you to glimpse the beach to the north, but you can't find a way through "
    "to it. "
    "\n\n");
    add_item("beach","From here all you can see is white sand and not much "
    "else. "
    "\n");
    add_smell("air","There is a faint hint of salt in the air, so you know "
    "you must be near the sea. "
    "\n");
}
void init()
{
    add_exit("east",HAVMAND+"j03.c","path");

    ::init();
}




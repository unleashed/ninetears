#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "Even though you are just off the beach, the trees seem to crowd "
    "in on you, making it difficult to make your way. You can still smell "
    "the salt in the air, but already the beach itself has almost disappeared "
    "from your sight. "
    "\n\n");
    add_item("beach","The beach is off to the east. From here about all you "
    "can see is that the sand is white, and the sea looks blue. "
    "\n");

}
void init()
{
    add_exit("east",HAVMAND+"b05.c","path");
    add_exit("west",HAVMAND+"j21.c","path");

    ::init();
}



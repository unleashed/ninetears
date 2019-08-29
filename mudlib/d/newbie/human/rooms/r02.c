#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Rocks\n\n"
    "   The needle-sharp rocks are incredibly wet and slippery, and you will "
    "have to be careful not to slip and seriously hurt yourself. The waves "
    "crashing against the rock creates huge clouds of spray, wetting "
    "everything. To the north you can see a nice, white, sandy beach. "
    "\n\n");
    add_item("beach","White sand stretches north as far as you can see.\n");

}
void init()
{
    add_exit("west",HAVMAND+"r01.c","path");
    add_exit("north",HAVMAND+"b05.c","path");

    ::init();
}

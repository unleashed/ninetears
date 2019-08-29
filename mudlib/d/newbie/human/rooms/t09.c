#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "This seems to be as far south as you can go on this little dirt track. "
    "It just sort of ends at the edge to the jungle. To the west you can "
    "see a gate in the castle wall, but it doesn't look as if it's had much "
    "use in a long, long time. "
    "\n\n");
    add_item("gate","Its difficult to see from here, but it looks like "
    "its made from very solid wood with steel bands across it.\n");

}
void init()
{
    add_exit("north",HAVMAND+"t08.c","path");
    add_exit("west",HAVMAND+"g00.c","path");
    add_exit("east",HAVMAND+"j15.c","path");

    ::init();
}


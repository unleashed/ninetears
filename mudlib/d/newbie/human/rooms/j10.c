#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You are on the eastern side of a precarious rope-bridge. The jungle "
    "continues all round you, and seems to be closing in more than ever. "
    "The trees seem very close to you and you can only go forward or back "
    "from here. "
    "\n\n");
    add_item( ({"rope-bridge","bridge"}),"This is a frail-looking bridge "
    "made from vines from the jungle. It crosses over a deep crevase, and "
    "you hope it is stronger than it looks. "
    "\n");
    add_item("crevase","The crevase is too wide to jump over, and looks to "
    "be very deep. You certainly wouldn't want to fall into it, and it looks "
    "as though you will have to use the bridge if you want to get to the "
    "other side. "
    "\n");
    add_item( ({"vine","vines"}),"Long vines hang from some of the trees. "
    "They look to be very strong and useful. Obviously whoever made the "
    "rope-bridge thought so. "
    "\n");

}
void init()
{
    add_exit("west",HAVMAND+"j09.c","path");
    add_exit("east",HAVMAND+"j16.c","path");

    ::init();
}



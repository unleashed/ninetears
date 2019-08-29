#include "path.h"
inherit HERE+"jungle.c";

void setup()
{
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The trees seem to be a bit thinner here. You can catch glimpses of a "
    "beach to the west, and the sea to the north, but you can't find a way "
    "to get to either of them. "
    "\n\n");
    add_item("beach","Its a bit hard to see from here, but it looks as though "
    "it is covered in white sand. "
    "\n");
    add_item("sea","You get a vague impression of spray and waves, but you "
    "can't get close enough to see clearly. "
    "\n");
    add_sound("sea","Now that you listen carefully, you can hear waves crashing "
    "onto rocks and the distant calls of seabirds. "
    "\n");

}
void init()
{
    add_exit("south",HAVMAND+"j04.c","path");

    ::init();
}



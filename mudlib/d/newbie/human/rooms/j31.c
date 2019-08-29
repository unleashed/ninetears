#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "As you travel further down this path it gets a little steeper and "
    "damper underfoot. There are still plenty of trees all around you, "
    "and there are some interesting-looking toadstools growing against the base "
    "of some of them here. The sound of falling water is getting louder. "
    "\n\n");
    add_item("toadstools","Dark brown and lethal looking toadstools are growing "
    "round the base of some of the trees. They seem to like the damp "
    "conditions here. "
    "\n");
    add_sound("water","It sounds like there must be a waterfall somewhere "
    "nearby. "
    "\n");

}
void init()
{
    add_exit("northeast",HAVMAND+"j30.c","path");
    add_exit("south",HAVMAND+"j32.c","path");

    ::init();
}



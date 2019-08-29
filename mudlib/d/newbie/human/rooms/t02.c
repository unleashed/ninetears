#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "This dusty little road turns to the south and west here, which has "
    "resulted in extremely deep ruts caused by wagons taking the "
    "corner too quickly some time in the past. In fact, you can see some "
    "broken bits of wagon wheel on the side of the track, showing that one "
    "wagon at least, never quite made it round. "
    " There is also a little trail cut into "
    "the jungle, but you aren't sure you want to go in there just yet. "
    "Further to the south you think you can see a way into the hovels of "
    "the village. "
    "\n\n");
    add_item("wheel","Old, rotten and useless, it is still recognizable as "
    "having come from a wagon, although it must have been a long time ago.\n");

    add_exit("west",HAVMAND+"t01.c","path");
    add_exit("east",HAVMAND+"j05.c","path");
    add_exit("south",HAVMAND+"t03.c","path");
}

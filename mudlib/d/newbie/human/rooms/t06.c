#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "This part of the track doesn't seem to have had so much vehicular traffic "
    "as further north, or at least the ruts in the ground don't seem so deep "
    "here. There is another small building to the west, and more jungle to "
    "the east. The track continues north and south. "
    "\n\n");

}
void init()
{
    add_exit("north",HAVMAND+"t05.c","path");
    add_exit("south",HAVMAND+"t07.c","path");
    add_exit("west",HAVMAND+"v04.c","path");
    add_exit("east",HAVMAND+"j11.c","path");

    ::init();
}

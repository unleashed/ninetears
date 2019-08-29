#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "You are walking along a small dirt track in front of a grotty little "
    "village nestled under a towering castle wall. On the other side of the "
    "track is the inevitable jungle. One day you really are going to have "
    "to find a way off this grotty little island. In the meantime, the "
    "hovel to the west looks suspiciously like a tavern of sorts. Maybe "
    "it would be a good place to drown your sorrows. "
    "\n\n");

}
void init()
{
    add_exit("west",HAVMAND+"v01.c","path");
    add_exit("east",HAVMAND+"j06.c","path");
    add_exit("north",HAVMAND+"t02.c","path");
    add_exit("south",HAVMAND+"t04.c","path");

    ::init();
}


#include "path.h"
inherit HAVMAND+"track.c";
void setup()
{
    
    set_long("\nIsle of Havmand : Track\n\n"
    "You are on a small dirt track separating a tiny collection of "
    "hovels from a deep and imposing jungle. The whole place looks to be "
    "deserted but you decide to keep a sharp lookout just in case it isn't. "
    "On one side of the track you see a pair of small birds enjoying a dust "
    "bath, but they fly away when you try to get a closer look at them. "
    "\n\n");
    add_item(({"bird","birds"}),"Two small black birds enjoying a dust bath. "
    "They are unfamiliar to you. \n");

}
void init()
{
    add_exit("north",HAVMAND+"t04.c","path");
    add_exit("south",HAVMAND+"t06.c","path");
    add_exit("west",HAVMAND+"v03.c","path");
    add_exit("east",HAVMAND+"j09.c","path");

    ::init();
}

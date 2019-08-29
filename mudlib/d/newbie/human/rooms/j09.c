#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "This is just the beginning of the trees and they look sort of friendly "
    "in an odd sort of way. At least they aren't threatening. To the west is "
    "a dirt track and to the east there is a rope-bridge. Will you be brave "
    "enough to cross it? "
    "\n\n");
    add_item( ({"bridge","rope-bridge"}),"The bridge is made from vines "
    "cut from the jungle, and looks very unsteady. It crosses a deep crevase "
    "which is too wide to jump over and is the only way to get to the other "
    "side. "
    "\n");
    add_item("crevase","The crevase is very wide and deep. In fact you can't "
    "see the bottom of it no matter how hard you look. It is too wide to jump "
    "over and you definately don't want to fall in to a certain death. "
    "\n");

}
void init()
{
    add_exit("west",HAVMAND+"t05.c","path");
    add_exit("east",HAVMAND+"j10.c","path");
    add_exit("north",HAVMAND+"j07.c","path");
    add_exit("south",HAVMAND+"j11.c","path");

    ::init();
}



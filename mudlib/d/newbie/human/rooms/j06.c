#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "Just outside a small village and already the trees feel like they are "
    "closing in on you. Its a good thing you don't suffer from claustrophobia "
    "or you would be starting to have real problems. There are lots of trees "
    "around you, but not a lot else, so its lucky you can see a kind of track "
    "heading north and south as well as the path back to the relative safety "
    "of the village. "
    "\n\n");
    add_item("village","Hardly a village at all really, more like a small "
    "group of houses that just happen to be together. "
    "\n");
    add_item("track","The track you are on is really just where someone has "
    "managed to hack a way through the jungle. "
    "\n");

}
void init()
{
    add_exit("north",HAVMAND+"j05.c","path");
    add_exit("south",HAVMAND+"j07.c","path");
    add_exit("west",HAVMAND+"t03.c","path");
    add_exit("southeast",HAVMAND+"j08.c","path");


    ::init();
}



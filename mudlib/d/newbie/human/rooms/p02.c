#include "path.h"
inherit HAVMAND+"pirate.c";

void setup()
{
    
   set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.\n");
    set_long("\nIsle of Havmand: Pirate Camp.\n"
    "   This is where several pirates camp. They were shipwrecked a while back "
    "and survive by eating various types of seafood, and foraging in the jungle. "
    "Unfortuneately, they often scrounge round the village for anything they "
    "might want as well, and generally they are a nuisance. \n"
    "A tatty hammock hangs between two trees and there are a number of empty "
    "bottles lying on the ground. A few rusty scabbards are lying around as "
    "well, but you can't see any weapons that would fit them. "
    "\n\n");
    add_item("hammock","This hammock is where one of the pirates sleeps. It is "
    "verry tatty and is almost falling apart.\n");
    add_item("bottles","Empty bottles lying around, it looks as though these "
    "pirates are heavy drinkers.\n");
    add_item(({"scabbard","scabbards"}),"They are really rusty and don't look "
    "as if they have been moved in a long time. There is no sign of any weapons.\n");
add_item("trees","The trees have been partially cleared here for the pirate camp.  \n");

}
void init()
{
    add_exit("west",HAVMAND+"j16.c","path");
    add_exit("east",HAVMAND+"p03.c","path");
    add_exit("north",HAVMAND+"j19.c","path");
    add_exit("south",HAVMAND+"j18.c","path");
    add_exit("southeast",HAVMAND+"p04.c","path");

    ::init();
}


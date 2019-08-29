#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "There is a small spring here. Water bubbles up from the ground, trickles "
    "along the track, and then disappears underground again. Tall tree ferns "
    "grow all around it, really thriving in the moist conditions. "
    "\n\n");
    add_item( ({"spring","water"}),"This is a small freshwater spring. "
    "After coming up from the ground, the water runs along the ground before "
    "disappearing once more, "
    "\n");
    add_item( ({"ferns","tree ferns","fern"}),"As tall as a tall man, these "
    "ferns have large bright green fronds branching out from brown trunks. "
    "\n");
    add_sound( ({"bubbles","water","trickles"}),"The water gurgles and chuckles "
    "its way out of the ground, along the path, and gurgles its way back "
    "into the ground. "
    "\n");

}
void init()
{
    add_exit("north",HAVMAND+"j31.c","path");
    add_exit("southeast",HAVMAND+"j33.c","path");

    ::init();
}



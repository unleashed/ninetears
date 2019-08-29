#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "As the rock closes in on you, it is really starting to get hot and "
    "humid down here. Your ears are filled with the sounds of dripping "
    "water, and small gnats swarm in the air as you move. Quite a bit "
    "of the dripping water seems to find its way to the ground via your neck. "
    "Despite the warm air it's unpleasantly cold and clammy. "
    "The moss underfoot forms large soft cushiony hummocks that squelch "
    "unpleasantly when you move. "
    "\n\n");
    add_item("moss","It's thicker , green and most definately wetter "
    "than you've seen before, it also forms unpleasantly suggestive "
    "shapes on the ground, like buried skulls and torsos "
    "\n");
    add_sound("water","Drip ..... drip ..... drip ..... Squelch.. "
    "(you moved) "
    "\n");
    add_feel("moss","Yetch, it's like grabbing a handfull of water !\n");
    add_item("gnats","Almost too small to see, they certainly swallow easilly, "
    "you spit, it doesn't help much.\n");
    add_taste(({"gnat","gnats"}),"Gritty, definately gritty, otherwise "
    "tasteless.\n");
}
void init()
{
    add_exit("west",HAVMAND+"j37.c","path");
    add_exit("southeast",HAVMAND+"j35.c","path");

    ::init();
}



#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The track falls away sharply to the northwest, and it looks "
    "like you are going to have to scramble going back down. "
    "To the northeast it appears that the jungle may be opening out."
    "The leaf litter on the forest floor is thinner here and small "
    "rocks show through."
    "\n\n");
    add_item("rocks",
    "The rocks are very rough and have a dirty reddish tinge to them, "
    "they are very weathered and appear to be quite crumbly. "
    "\n");

}
void init()
{
    add_exit("southwest",HAVMAND+"j29.c","path");
    add_exit("northwest",HAVMAND+"j27.c","path");

    ::init();
}





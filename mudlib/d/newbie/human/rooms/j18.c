#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The jungle here is very dense. There is no way through the trees except "
    "by going back through the pirates camp. It might be a good idea to be "
"very quiet though, because those pirates can get upset if they see "
    "strangers hanging around. "
    "\n\n");

}
void init()
{
    add_exit("north",HAVMAND+"p02.c","path");
    add_exit("east",HAVMAND+"p04.c","path");


    ::init();
}



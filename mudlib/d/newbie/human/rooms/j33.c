#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "The path is definately getting steeper and also narrower. There are "
    "less trees than before, but unfortunately there are now rocks on the "
    "path making it more difficult to walk. If you aren't careful you are "
    "going to damage your ankles. "
    "\n\n");
    add_item("rocks","Fist sized rocks are scattered along the path. You "
    "will need to be careful where you put your feet. "
    "\n");

}
void init()
{
    add_exit("east",HAVMAND+"j34.c","path");
    add_exit("northwest",HAVMAND+"j32.c","path");

    ::init();
}



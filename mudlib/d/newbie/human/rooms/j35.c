#include "path.h"
inherit HAVMAND+"jungle.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Jungle\n\n"
    "You are on a downward spiralling path which gets steeper the "
    "further down you go. The trees have almost disappeared and have been "
    "replaced by rock. Now that you look round, you realise you are "
    "walking between two huge rock faces with moss and lichen growing over "
    "them. It is certainly very humid down here. "
    "\n\n");
    add_item(({"rock","rocks","rock face","rock faces"}),
    "Two huge rock faces tower over you on either side of the path. They are "
    "covered with lichen and moss. "
    "\n");
    add_item("lichen","Scaly, frondlike plants growing on the rock face. "
    "\n");
    add_item("moss","Soft green moss is growing on the rock face. "
    "\n");

}
void init()
{
    add_exit("northwest",HAVMAND+"j36.c","path");
    add_exit("southwest",HAVMAND+"j34.c","path");

    ::init();
}



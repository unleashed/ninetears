#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   The fine white sands of the beach come to an end here. Further south "
    "you can see rocks coming up out of the sea, and there is a small trail "
    "into the jungle. As you watch, you see a small mollusc disappear "
    "into the sand. A gentle seabreeze ruffles your hair. "
    "\n\n");
    add_item(({"rock","rocks"}),"Sharp, volcanic rocks, if you are going to "
    "explore them you will need to be careful.\n");
    add_item("mollusc","A shellfish of some sort, it disappears before you can "
    "get a good look at it.\n");
    add_feel("breeze","A soft breeze gently ruffles your hair.\n");

}
void init()
{
    add_exit("north",HAVMAND+"b04.c","path");
    add_exit("south",HAVMAND+"r02.c","path");
    add_exit("west",HAVMAND+"j22.c","path");

    ::init();
}

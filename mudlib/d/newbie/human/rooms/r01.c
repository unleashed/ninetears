#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Rocks\n\n"
    "   You are scrambling over very sharp rocks. They are slippery as well, "
    "making you extremely cautious. There are a lot of small shellfish "
    "clinging tightly to the rocks and obviously they thrive in the wet "
    "conditions caused by the continual spray from the sea. "
    "\n\n");
    add_item("shellfish","Mussels, pipis and limpets cling tightly to the "
    "rocks.\n");
    add_item("spray","You and everything else are getting very wet from the "
    "spray thrown up by the sea hitting the rocks.\n");

}
void init()
{
    add_exit("east",HAVMAND+"r02.c","path");

    ::init();
}

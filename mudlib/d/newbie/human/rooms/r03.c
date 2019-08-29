#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Rocks\n\n"
    "   These rocks are very sharp and have nasty jagged edges. They are also wet "
    "and very slippery. Many small shellfish are firmly attached to them. Far "
    "out to sea you can see a small boat of some type, and birds circle "
    "overhead. "
    "\n\n");
    add_item("shellfish","Mussels, pipis and limpets cling to the sides of "
    "the rocks.\n");
    add_item("boat","You can't see it clearly, but you assume its a fishing "
    "vessel of some type.\n");
    add_item(({"bird","birds"}),"Sea birds circle overhead, scanning the sea "
    "for food.\n");

}
void init()
{
    add_exit("east",HAVMAND+"r04.c","path");

    ::init();
}

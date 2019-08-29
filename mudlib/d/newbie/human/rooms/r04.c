#include "path.h"
inherit HAVMAND+"rock.c";

void setup()
{
    
    set_long("\nIsle of Havmand : Rocks\n\n"
    "   These sharp jagged rocks are a reminder that this island was once an "
    "active volcano. To the south is the pleasant white sands of a beach and "
    "to the north and east is the sea. A small starfish is lying in a rockpool "
    "here and there are many shellfish clinging to the rocks. "
    "\n\n");
    add_item("starfish","A small five-pointed starfish sitting in a rockpool.\n");
    add_item("rockpool","A small pool of water has collected in a cranny in "
    "the rocks.\n");
    add_item("shellfish","Mussels, pipis and limpets.\n");

}
void init()
{
    add_exit("west",HAVMAND+"r03.c","path");
    add_exit("south",HAVMAND+"b01.c","path");

    ::init();
}

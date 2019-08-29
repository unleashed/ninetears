#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "   The white sandy beach stretches north and south, seemingly endlessly. "
    "The deep blue of the sea looks cool and refreshing, and as you stare "
    "out to sea you think you can see a boat far away in the distance. There "
    "is thick jungle to the west and no way you can enter it from here."
    "\n\n");
    add_item("boat","It is too far away to see clearly, and you can only "
    "assume it is a fishing vessel of some sort.\n");
    add_item("jungle","Deep, impenetrable trees come right down to the "
    "beachfront. Their intertwining trunks make it impossible to hack a "
    "way through.\n");

}
void init()
{
    add_exit("north",HAVMAND+"b02.c","path");
    add_exit("south",HAVMAND+"b04.c","path");

    ::init();
}


#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.\n");
    set_long("\nIsle of Havmand: Pirate Camp.\n"
      "   Impenetrable jungle looms to the south, but you notice a couple of "
      "hammocks hanging between some of the trees. The path to the campfire "
      "is to the north and more of the campsite is to the east. There is general "
      "clutter everywhere and the whole place somehow looks untidy. "
    "\n\n");

   add_item("jungle","Heaps of trees growing closely together, their twisted "
      "trunks make it difficult to find a way through them. \n");

   add_item("hammocks","String hammocks are strung between the trees. They "
      "are very tatty, and you wouldn't want to trust them with your weight.\n");

   add_item("clutter","Cast-off old clothes, empty bottles, and general rubbish "
      "litters the whole campsite. Pirates are not very tidy people it seems. \n");

}
void init()
{
    add_exit("west",HAVMAND+"j18.c","path");
    add_exit("east",HAVMAND+"p05.c","path");
    add_exit("north",HAVMAND+"p03.c","path");
    add_exit("northwest",HAVMAND+"p02.c","path");

    ::init();
}

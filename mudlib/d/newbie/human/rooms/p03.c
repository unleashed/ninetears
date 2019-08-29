#include "path.h"
inherit HAVMAND+"pirate.c";
void setup()
{
    
   set_light(LIGHT);
    set_short("Isle of Havmand: Pirate Camp.\n");
    set_long("\nIsle of Havmand: Pirate Camp.\n"
    "   This is the centre of the pirates camp. There is a large campfire in "
    "in the middle of the clearing with a number of rocks around it. Bones and "
    "empty bottles lie discarded round the edges, and it is a generally untidy "
    "sort of place. "
    "\n\n");
    add_item(({"fire","campfire"}),"A large circle of blackened rocks with "
    "smouldering embers in the centre. It is where the pirates cook their food, "
    "and gather round in the evenings for warmth and companionship.\n");
    add_item("bones","The bones of whatever the pirates eat, they are just "
    "thrown away when the meat has been eaten from them. It would be much neater "
    "if they had been thrown into the fire to burn.\n");
    add_item("bottles","Empty bottles which once held alcoholic beverages.\n");
    add_item(({"rock","rocks"}),"Large rocks have been placed around the fire "
    "and are used as seats.\n");

}
void init()
{
    add_exit("west",HAVMAND+"p02.c","path");
    add_exit("south",HAVMAND+"p04.c","path");
    add_exit("northeast",HAVMAND+"p01.c","path");
    add_exit("southeast",HAVMAND+"p05.c","path");

   ::init();

}

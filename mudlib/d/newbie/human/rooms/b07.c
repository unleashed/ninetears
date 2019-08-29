#include "path.h"
inherit HAVMAND+"beach.c";

void setup()
{
    
   set_light(LIGHT);
    set_long("\nIsle of Havmand : Beach\n\n"
    "This is a very small beach, but it is covered in fine white sand and looks "
    "very peaceful. There is jungle to the east and south, and the beach "
    "continues to the west. Sparkling blue water laps at the shoreline. "
    "There is the remains of an open fire, showing that someone spends "
    "some of their time here."
    "\n\n");
    add_item("fire","Blackened rocks where someone has lit a fire, possibly "
    "to cook or maybe to just keep warm.\n");

}
void init()
{
    add_exit("west",HAVMAND+"b06.c","path");
    add_exit("south",HAVMAND+"j03.c","path");

    ::init();
}

#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Dead End");
set_light(40);
set_long("\n   Realm of the Orc:  Dead End.\n\n"
         "     You stand before a large gate, too bad its not openable "
         "from this side.  "
    "The only other exit is to the west down the road. "
    "It leads down the mountain to some city in the distance. "
    "\n\n");
add_exit("west",TOWN +"road2.c","road");
}

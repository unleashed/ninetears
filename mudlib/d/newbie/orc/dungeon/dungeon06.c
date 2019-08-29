#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Central Passageway Section");
set_light(40);
set_long("\n   Realm of the Orc:  Central Passageway Section.\n\n"
         "     This is a small passageway which leads directly "
         "through the center of palace dungeon. To the north and "
         "south there are small cells.  To the west you can "
         "barely notice a dim light burning.  Looking closely "
         "towards the east, you think you see an abrupt dead "
         "end.\n\n");


add_property("no_undead",1);
add_exit("north",DUNGEON +"dungeon02","door");
add_exit("west",DUNGEON +"dungeon05","door");
add_exit("south",DUNGEON +"dungeon11","door");
add_exit("east",DUNGEON +"dungeon07","door");
}

#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Guard Post");
set_light(40);
set_long("\n   Realm of the Orc:  Guard Post.\n\n"
         "     This was once a watch post for the guards that kept "
            "guard on the prisoners in the cells here.  It has not "
            "been used since the cave-in and anyone here must have "
            "gotten here the same way you did.  There is not that much "
            "is of interest to you here.  "
            "\n\n");
add_exit("south",DUNGEON +"dungeon13","door");
add_exit("north",DUNGEON +"dungeon04","door");
add_exit("west",DUNGEON+"dungeon07","door");
}
void init()
{
   ::init();
   add_action("go_west","w*est");
}
int go_west(string str)
{
   write("The passage is blocked by the cave-in.\n");
   return 1;
}

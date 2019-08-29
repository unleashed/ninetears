#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Central Passageway Section");
set_light(40);
set_long("\n   Realm of the Orc:  Central Passageway Section.\n\n"
         "     You are now surrounded by cells in many directions "
         "Crossing along the southeast corner there is a pile of "
         "rubbish which partially blocks the exits to the south "
         "and east.  If you are lucky, you might be able to "
         "pass through.\n\n");
add_item(({"pile","rubbish"}),"\nThis rubble is the result of a "
           "large cave-in that resulted from the years of neglect "
           "that the castle has encountered.  With this pile "
           "here, the exits to the east and south appear to be "
           "blocked.");
add_exit("south",DUNGEON + "dungeon07","door");
add_exit("east",DUNGEON + "dungeon07","door");
add_exit("west",DUNGEON +"dungeon06","door");
add_exit("north",DUNGEON +"dungeon03","door");
}
void init()
{
   ::init();
   add_action("go_east","e*ast");
   add_action("go_east","s*outh");
}
int go_east()
{
   write("  The passage is blocked by the cave-in. \n");
   return 1;
}

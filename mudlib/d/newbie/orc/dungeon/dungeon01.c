#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Dungeon Entrance");
set_light(40);
set_long("\n   Realm of the Orc:  Dungeon Entrance.\n\n"
         "     You are in the entrance to the palace dungeon.  "
         "From here you can see a staircase which leads up "
         "towards the surface.  To the south you can see a dim "
         "light burning.  At close inspection of the room, you "
         "notice a dead corpse underneath the stairs.\n\n");

add_item(({"staircase","stair","stairs"}),"\nThese stairs are "
           "made of stone.  There are about 50 stairs leading "
           "upward in a spiriling direction.\n");

add_item(({"corpse","remains"}),"\nThis is the skeletal remains "
           "of one of the guards that used to protect this palace "
           ".  With the condition of this corpse, it looks as if "
           "the body has been here for ages.\n");

add_exit("south",DUNGEON +"dungeon05","door");
add_exit("up",CASTLE +"orc10","door");
}

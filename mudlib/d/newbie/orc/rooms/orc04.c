//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The light from the fire in the throneroom casts an "
            "erie glow on the hallway.  The hall ends apruptly here, "
            "as a blood-stained wall prohibits you from going west.  "
            "There is an opening to the south where a door has been "
            "torn down that leads into a small room.  The throne room "
            "is to the east.  "
            "\n\n");
   add_item(({"blood","wall"}),"  The walls are covered with thick "
       "blotches of dried blood.\n");
add_exit("south",CASTLE +"orc10","door");
add_exit("east",CASTLE +"orc05","door");
}

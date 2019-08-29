//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Sharp Bend");
set_light(40);
   set_long("\n   Realm of the Orc:  Sharp Bend.\n\n"
            "     The hallway here bends sharply going north and "
            "west.  To the north, at the end of the hall, you can "
            "see what was once the throne room.  It looks to be in "
            "pretty bad shape, even from this distance.  The light "
            "from the north is flickering, as if there were a large "
            "fire up there.  To the west you can see the hallway "
            "that leads to the entrance.  "
            "\n\n");
   add_item(({"throne","throneroom","fire"}),"  You cannot see much "
       "from this distance.\n");
add_exit("north",CASTLE +"orc11","door");
add_exit("west",CASTLE +"orc16","door");
}

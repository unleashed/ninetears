//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Small Room");
set_light(40);
   set_long("\n   Realm of the Orc:  Small Room.\n\n"
            "     The shelves on the wall of this small room indicate "
            "that it was once used as a storage area.  Most of the "
            "shelves are broken or missing.  The few that remain are "
            "completely bare, their contents emptied by those that "
            "invaded here long ago.  There is a small doorway to the "
            "north and a tiny spiral staircase that leads down "
            "into blackness.  "
            "\n\n");
   add_item(({"wall","shelf","shelves"}),"  The shelves are mounted "
       "in a small recess in the wall.  Very few remain intact.  Those "
       "that do have been completely emptied of their contents.\n");
   add_item("recess","  The recess serves to place the shelves out "
       "of the way.\n");
add_exit("north",CASTLE +"orc04","door");
add_exit("down",DUNGEON +"dungeon01","stair");
}

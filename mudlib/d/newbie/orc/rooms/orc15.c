//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Tower of Grishnath, Main Entrance");
set_light(40);
   set_long("\n   Realm of the Orc:  Tower of Grishnath, Main Entrance.\n\n"
            "     You are standing at the main entrance to the "
            "tower.  The room must have been quite a sight long "
            "ago.  But now the place is in a state of advanced "
            "decay.  The walls are crumbling and the ceiling is "
            "full of holes that have allowed water to enter and "
            "ruin the floor.  "
            "There is a gate to the south under the stone "
            "archway.  To the north, you can procede down the dark "
            "hallway and to the east into the castle.  "
            "\n\n");
   add_item(({"gate","archway"}),"  The stone archway marks the "
       "entrance to the castle in what was once a grand fashion.  "
       "The gate could be raised or lowered to welcome or discourage "
       "visitors here.  Since the gate has been ripped from its "
       "mountings, you get the feeling that those who last visited here "
       "were highly unwelcome.\n");
   add_item(({"door","floor","wall","ceiling","holes"}),"  The "
       "entire room has been destroyed by the invading forces.  "
       "The ceiling is full of holes and the water is allowed through "
       "has ruined the walls and floor here.\n");
add_exit("south",CASTLE +"orc19","door");
add_exit("north",CASTLE +"orc09","door");
add_exit("east",CASTLE +"orc16","door");
}
 
 

//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The stone floor is the only thing in this place "
            "that is still intact.  The walls have been gouged "
            "by some form of sharp weapon, the tapestries that "
            "once hung here are nothing but tatters of canvas "
            "that litter the room, and the bones of some deceased "
            "creature rest against the walls.  It is beginning to "
            "look like this tower was taken by some hostile and "
            "cruel force.  The hallway continues to the east and "
            "opens up into the entrance chamber to the west.  "
            "\n\n");
   add_item(({"remains","bones","creature"}),"  The pile of bones "
       "is quite large and you now believe it to be more than one "
       "creature.\n");
   add_item("floor","  The floor is littered with the remains of "
       "some poor creatures and scraps of canvas.\n");
   add_item(({"scrap","canvas"}),"  The scraps of canvas are all that "
       "remain of the paintings that once hung in this grand "
       "hallway.\n");
   add_item(({"wall","tapestries"}),"  The walls that were once "
       "adorned with tapestries are now covered with dried blood and "
       "marks left by the bite of some blade.  The remains of the "
       "tapestries are now just piles of torn canvas in the floor.\n");
add_exit("east",CASTLE +"orc17","door");
add_exit("west",CASTLE +"orc15","door");
}

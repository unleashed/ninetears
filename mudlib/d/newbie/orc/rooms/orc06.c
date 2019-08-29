//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The flickering light from the throne room causes you "
            "to jump as shadows leap at you from the walls.  The "
            "hallway runs between the throneroom and several smaller "
            "rooms to the east.  "
            "A horrible smell greets you from the south from what "
            "looks like a dining room.  "
            "The carpeting on the floor is charred from a fire and "
            "soaked by the weather.  The walls and ceiling are covered "
            "with a thin layer of dark black soot.  Water droplets "
            "trickling down the walls resemble tears streaking "
            "down a dirty cheek.  A cold chill runs down your spine "
            "and you are forced to shake off these eerie feelings.  "
            "\n\n");
   add_item(({"carpet","wall","soot"}),"  The walls and carpet make "
       "you think that there was a large fire that burned through "
       "here.  The carpet is charred and the walls are covered with "
       "the thick black soot.\n");
   add_item(({"droplet","water"}),  "The water droplets are trickling "
       "down the soot covered walls.\n");
add_exit("south",CASTLE +"orc12","door");
add_exit("east",CASTLE +"orc07", "door");
add_exit("west",CASTLE +"orc05","door");
}

//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The filthy walls here support what is left of the "
            "once magnificent ceiling.  The roof has fallen in and "
            "allowed the rains to enter and flood the floor here.  "
            "The water is not very deep, but it is cold and sends a "
            "a shiver up your spine.  There is a sound coming from "
            "somewhere above.  The hall continues to the north and "
            "south.  "
            "\n\n");
   add_item(({"wall","ceiling","roof"}),"  The walls, just like "
       "the ceiling are quickly falling apart.  The weather seems "
       "to be the primary cause for this.  The rains have washed the "
       "blood from the walls, however, it has taken much of the wall "
       "away too.\n");
   add_item("water","  The water is just deep enough to make you dread "
       "moving through it.  It looks to be very unclean and extremely "
       "cold.\n");
add_exit("south",CASTLE +"orc15","door");
add_exit("north",CASTLE +"orc03","door");
}

//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The hallway here is brightly lit by the light "
            "coming from the room to the north.  It appears to "
            "to be produced by a large fire and the smell of smoke "
            "makes you wonder just what might be burning.  You can "
            "go north into the throne room or head south to a "
            "bend in the tunnel.  "
            "\n\n");
add_exit("south",CASTLE +"orc17","door");
add_exit("north",CASTLE +"orc05","door");
}

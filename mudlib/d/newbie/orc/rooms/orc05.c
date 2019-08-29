//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Throne Room");
set_light(80);
   set_long("\n   Realm of the Orc:  Throne Room.\n\n"
            "     This large, brightly lit room was once the throne "
            "room for the ruler of this area.  But now, time has "
            "taken a toll on the once elegant room.  The furniture "
            "is all broken and rotting here on the floor.  The "
            "carpeting has been burned and is now nothing more "
            "than ashes.  The paintings on the walls have been "
            "cut and ripped apart, their elegant frames destroyed "
            "and thrown about in the room.  The throne remains "
            "somewhat intact and looks if it has been in recent use.  "
            "Up against the walls to the east and west are large "
            "fires that only worsen the already horrible smell "
            "that fills the air here.  "
            "There are hallways to the east and south and a room "
            "to the east.  "
            "\n\n");
   add_item(({"furniture","paintings","frame","carpeting"}),"  The "
       "contents of this room have been totally destroyed.  The "
       "remains of all the items that once filled this room are either "
       "rotting on the floor or burning in the fires.\n");
   add_item("wall","  The walls are difficult to see for the fires.  "
       "What you can see are just plain, empty walls.  Anything of value "
       "has been taken away or destroyed. \n");
add_item("throne"," The throne is still in suprisingly good shape "
       "considering the condition of the rest of the room.  Those that "
"caused all of this destruction must have wanted to keep it "
       "for some reason.\n");
//NPC'S
add_clone(CHAR+"chief",1);

//exits
add_exit("south",CASTLE +"orc11","door");
add_exit("east",CASTLE +"orc06","door");
add_exit("west",CASTLE +"orc04","door");
}

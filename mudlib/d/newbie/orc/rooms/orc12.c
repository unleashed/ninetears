//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Dining Room");
set_light(40);
   set_long("\n   Realm of the Orc:  Dining Room.\n\n"
            "     This incredibly long room must have once been a "
            "great feasting hall for the occupants of the tower.  "
            "The remains of a very long table rest on the floor "
            "along with several chairs.  This room was not spared "
            "by the onslaught of invaders, as indicated by the blood "
            "stains and blade marks on the wall,as well as, the "
            "bones that litter the floor here.  The main hall is to "
            "the north and the dining room continues to the east.  " 
            "\n\n");
   add_item(({"remains","table","chairs"}),"  The table and chairs "
       "were completely destroyed by the battle.  Their remains are "
       "scattered along the floor.\n");
   add_item(({"wall","blood","stain","marks"}),"  Flaking blood "
       "stains the walls here to the extent that you are barely "
       "able to make out the marks in the wall from the weapons "
       "used to fight in this battle.\n");
   add_item(({"floor","bones"}),"  There are a large number of bones "
       "here, scattered out across the floor.\n");
add_exit("north",CASTLE +"orc06","door");
add_exit("east",CASTLE +"orc13","door");
}

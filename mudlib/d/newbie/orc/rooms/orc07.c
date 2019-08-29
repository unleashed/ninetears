//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The hallway here connects the throneroom to the "
            "bedroom with the dining area to the south.  The stones "
            "that make up the walls here are loose and crumbling.  The "
            "slightest touch sends down a shower of sand and grit to "
            "the already dirty floor.  Suprisingly, the carpeting here "
            "is not nearly as damaged as in other parts of the castle.  "
            "Through the door way to the south you can see what is left "
            "of the dining area.  The hallway continues to the west "
            "and the small doorway to the east leads into the bedroom.  "
            "\n\n");
   add_item(({"wall","stone"}),"  The wall has taken heavy damage "
       "here from the weapons used in the battle.  This hall must "
       "have been the site of heavy fighting.\n");
   add_item(({"sand","grit"}),"  The sand and grit shower to a pile "
       "on the floor with just a slight touch to the wall.\n");
   add_item(({"floor","carpet","carpeting"}),"  The carpet here is "
       "still mostly intact.  The entire floor is filthy with sand "
       "and blood.\n");
   add_item("pile","  This is a small pile of rit and sand.  It has "
       "fallen from the walls.\n");
add_feel(({"walls","wall"}),
"\n"
" OUCH, SAND IN YOUR EYES!!! EEEK!\n");
add_exit("south",CASTLE +"orc13","door");
add_exit("east",CASTLE +"orc08","door");
add_exit("west", CASTLE +"orc06","door");
}


//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain

#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Narrow Passage");
set_light(40);
   set_long("\n   Realm of the Orc:  Narrow Passage.\n\n"
            "     This is the end of a long passageway.  The walls here "
            "have been stripped of all decorations long ago.  Now, only "
            "the stains of war can be seen upon the filthy walls.  The "
            "only light comes in from the huge room to the northwest.  "
            "You can see torches lining the rounded wall in there and "
            "a staircase that leads upward, going around the "
            "inside of the wall.  "
            "The hallway continues to the south.  "
            "\n\n");
   add_item(({"torch","torches","staircase"}),"  You might get a better "
       "look at that if you were in the other room.\n");
   add_item(({"passageway","hallway"}),"The hallway here runs "
              "northwest and south.\n");
   add_item(({"stains","walls"}),"  The walls here have been damaged "
       "by the fighting that occured here.  There are marks on the "
       "walls that must have been made when a sword or axe dug into "
       "the stone.  Blood is splattered upon the wall, covering large "
       "areas with a sickening brownish-red color.\n");
   add_item("blood","  The blood is flaking off in several places "
       "allowing a better look at the stones underneath.\n");
   add_item(({"stone","stones"}),"  The stones are starting to "
       "crumble.  Is seems that this battle was too much for the "
       "old place to withstand.\n");
add_exit("south",CASTLE +"orc03","door");
add_exit("northwest",CASTLE +"orc01","door");
}

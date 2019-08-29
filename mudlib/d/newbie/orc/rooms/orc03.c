//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Hallway");
set_light(40);
   set_long("\n   Realm of the Orc:  Hallway.\n\n"
            "     The hallway leads north and south here.  The high, "
            "arched ceiling is almost hidden by the darkness.  From "
            "what you can see, it looks as if it was once painted "
            "with a beautiful mural.  But now, war and weather have "
            "taken their toll on the entire castle.  Several chunks "
            "of the ceiling have fallen to the floor.  The dirty "
            "walls hold a couple of small torches.  "
            "\n\n");
   add_item(({"ceiling","mural","chunk"}),"  The ceiling was once "
       "covered by some incredible mural.  Now the damage caused by "
       "war has caused the ceiling to fall and several large pieces "
       "of it lie here on the floor.\n");
   add_item("pieces","  These pieces of the ceiling are too large "
       "and heavy for you to move.\n");
   add_item(({"torch","torches","holder"}),"  The torches, which are "
       "firmly attached in their holders, are not lit and offer "
       "no light at all.\n");
   add_item(({"wall","blood","marks"}),"  The walls are covered with "
       "layer after layer of blood.  This combined with the massive "
       "number of marks on the wall indicate this was a heavily "
       "fought area.\n");
add_exit("south",CASTLE +"orc09","door");
add_exit("north",CASTLE +"orc02","door");
}

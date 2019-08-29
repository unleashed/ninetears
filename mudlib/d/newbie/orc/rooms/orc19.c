//    Orc Newbie Area -- Coded by Thane Mist -- MM Domain
  
 
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Drawbridge");
set_light(40);
   set_long("\n   Realm of the Orc:  Drawbridge.\n\n"
            "     You are standing on a rickety old drawbridge that "
            "crosses what was once a moat.  The bridge allows access "  
            "to the entrance of the tower and cannot be raised because "
            "the chains that were used for that have rusted and fallen "
            "apart.  You can go north into the tower or south toward "
            "the edge of the cliff.  "
            "\n\n");
   add_item(({"moat","bridge","drawbridge"}),"  The drawbridge was "
       "used to connect the castle entrance to the rest of the "
       "mountain top.  However, the moat has been filled in and "
       "is not much more than a ditch.  Upon closer inspection "
       "you realize that this moat was filled in with the dead "
       "bodies left from the battle here.  \n");
   add_item(({"entrance","tower"}),"  The tower looms above you "
       "as you stand before the entrance to the castle.\n");
   add_item("chain","  The chains that were once uset to hiost the "
       "drawbridge are broken.  As you look closer, it is evident "
       "that rust was not the reason for their breakage.  They "
       "were obviously cut.\n");
add_exit("south",CASTLE +"orc21","path");
add_exit("north",CASTLE +"orc15","path");
}

//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Flooded Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Flooded Cave\n\n"
            "   The knee deep water rushes past you heading to the east.  "
            "The floor of the cave here is angled downward sharply to "
            "the east and the sharp rocks all around add to the thundering "
            "fury of the river.  To the east you can see that the "
            "cave slopes downward even more and will likely make it "
            "impassible.  To the west, the water is much calmer and "
            "much safer.  "
		"\n\n");
add_exit("east",ROOM+"dwarf65","path");
add_exit("west",ROOM+"dwarf63","path");
}
void init(){
::init();
   add_action("go_e","e*ast");
   }

go_e()
{
   write("As you head to the east you suddenly realize the mistake you "
         "have made.  The force of the water drags you closer and "
         "closer to the sharp rocks that are everywhere below you.  "
         "Luckily, you find a good footing against a large stone and are "
         "able to pull yourself up onto a small ledge that runs along "
         "the cave wall, next to the river.  "
         "\n\n");
   return (0);
}

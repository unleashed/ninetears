//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Floded Cave");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Floded Cave\n\n"
            "   The thunderous sound of the water crashing onto the "
            "rocks outside echos throughout the cave causing eerie "
            "sounds to come from deep within.  The cave walls here are "
            "worn smooth from top to bottom, indicating that the water "
            "was likely much higher than the knee-high level that it "
            "is at now.  You realize that the cool water contains some "
            "creatures as you can feel them brushing up against you.  "
            "The cave splits here going south and southwest, deeper "
            "into the cave and north to the outside.  "
		"\n\n");
   add_item(({"cave","walls"}),"\n   The cave walls are smooth to the "
              "touch.  This is likely due to the water that is rushing "
              "through the cave.\n\n");
   add_item(({"water","creatures"}),"\n   Several small creatures dart "
              "about underneath the water here and brush against your "
               "leg.  You are unable to make out what they are, but "
               "they have not bitten you yet, so hopefully they are "
               "not dangerous.\n\n");
add_exit("north",ROOM+"dwarf24","path");
add_exit("south",ROOM+"dwarf41","path");
add_exit("southwest",ROOM+"dwarf40","path");
}

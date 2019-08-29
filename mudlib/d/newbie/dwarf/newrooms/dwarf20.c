//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Lake View");
set_zone("CAVE");
set_light(40);

   set_long("\n   Realm of the Dwarf:  Lake View\n\n"
            "You have come to a dead end on the pathway behind the "
            "waterfall.  Here the water from the lake runs up to and "
            "even underneath the cave wall that is to the west.  You "
            "can feel the cold spray of water from the waterfall "
            "and the water that is splashing onto you from the large "
            "waves that are caused when the water hits bottom.  "
		"\n\n");
   add_item(({"cave wall","wall"}),"The cave wall is very solid "
              "and mostly worn smooth by the water.  The water "
              "from the lake has cut in underneath the wall, but you"
              "don't think it would be wise to try to go underneath. "
              "\n\n");
   add_item(({"waterfall","water","waves","lake","falls"}),"The waterfall "
              "supplies water to the lake and keeps it full, while "
              "the whirlpool seems to be the water's means of exiting "
              "the lake.  "
              "\n\n");
   add_item(({"whirlpool"}),"The whirlpool churns up the water on "
              "the northern part of the lake.  It looks like the "
              "water from the lake is pouring out into some "
              "underground river.  "
              "\n\n");
add_exit("southeast",ROOM+"dwarf24","path");
}

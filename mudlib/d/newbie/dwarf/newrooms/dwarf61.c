//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom2.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave In");
set_zone("CAVE");
set_light(40);

	set_long("\n   Realm of the Dwarf:  Cave In\n\n"
            "   The passage comes to a stop here at the site of a large "
            "cave in.  What appears to have been a passage to the "
            "southwest at one time, is now completely blocked by the "
            "collaspe of the ceiling of the cave.  From what you can "
            "see of the cave walls and ceiling here, you are sure that "
            "it was all cut out by someone who was mining for something "
            "here.  The marks from picks are evident everywhere around "
            "the room.  The only exit here is the small passageway to the "
            "east.  "
		"\n\n");

   add_item(({"cave in","collapse","rubble","pile"}),"The ceiling has "
              "fallen in here and has left a large pile of rubble that "
              "blocks the way west\n\n"); 
   add_item(({"walls","ceiling","floor","marks"}),"The walls, ceiling "
              "and floor are covered with the marks left behind by "
              "someone with a pick who must have been looking for "
              "something. \n\n");
add_exit("east",ROOM+"dwarf62","path");
}

//  Dwarven Newbie Area:  Created By Mist   Fall 1994
//   Addition to the Dwarven Newbie Area:   Mist Spring 1997

#include "path.h"
inherit ROOM+"baseroom.c";

object caverat;
void setup ()   { my_setup();
set_short("Realm of the Dwarf:  Cave");
set_zone("CAVE");
set_light(40);

   set_long("\n               Realm of the Dwarf:  Behind Waterfall\n\n"

            "   The thunderous sound of the waterfall drowns out all "
            "other noise and makes it difficult to even think.  The "
            "water is soaking you as it falls into the lake and "
            "spills backwards into a small opening in the southern "
            "wall.  The opening is allowing a small river of water to "
            "escape and move quickly south. "
            "The pathway continues to the northwest.  "
		"\n\n");
   add_item(({"lake"}),"The waterfall completely blocks your view "
              "of the lake. "
              "\n\n");
   add_item(({"water","waterfall","spray","falls"}),"The waterfall is "
              "loudly spilling water into the lake and soaking you with "
              "its cold spray.  Any movement towards the falls could "
              "be disasterous, as the force of the falling water would "
              "be sure to pull you in.  "
              "\n\n");
   add_item(({"opening","river"}),"Some of the water from the falls "
              "is running through the opening in the southern wall.  "
              "\n\n");
add_exit("south",ROOM+"dwarf31","path");
add_exit("east",ROOM+"dwarf25","path");
add_exit("northwest",ROOM+"dwarf20","path");
}

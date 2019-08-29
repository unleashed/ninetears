#include "path.h"
inherit CASTLE+"baseroom.c";

void setup() { my_setup();
set_short("Realm of the Orc:  Western Passageway Section");
set_light(40);
set_long("\n   Realm of the Orc:  Western Passageway Section.\n\n"
         "     You now stand in the western edge of the "
         "passageway.  This passage leads to the east to the "
         "remainder of the dungeon.  In the northern room, "
         "there is a set of stairs that goes up, and there is a "
         "cell to the south.  Hanging on the western wall there "
         "is a dimly flickering torch which provides the light "
         "for the entire area.\n\n");
add_item(("torch"),"\nThis torch has a very small flame, but "
          "is just emough to provide minimal light for the "
          "majority of the dungeon.  Either someone else is "
          "here at the moment, or the person that lit it "
          "rushed to exit.");
add_exit("north",DUNGEON +"dungeon01","door");
add_exit("south",DUNGEON +"dungeon10","door");
add_exit("east",DUNGEON +"dungeon06","door");
}

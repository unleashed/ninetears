#include "path.h"
inherit CASTLE+"baseroom.c";

void setup ()   { my_setup();
set_short("Realm of the Orc:  Stairs");
set_light(40);
  set_long("\n   Realm of the Orc:  Stairs.\n\n"
           "     The stairs here follow the curvature of the wall as "
            "they disappear into darkness in both directions.  The "
             "walls here are covered with splotches of dried blood "
             "and marks made by swords and axes.  Torches that once "
             "were held in place here by their holders, have long "
             "since rotted away.  The stairs will lead you up or "
            "down.  "
             "\n\n");
add_item(({"wall","walls","blood","torches","marks"}),"\n"
"   The walls are blacked by the died blood of the fallen. "
"It appears the battle was fought in ever room and in every square foot.\n");
add_exit("up",TOWER +"tower05","room");
add_exit("down",TOWER +"tower03","room");
}

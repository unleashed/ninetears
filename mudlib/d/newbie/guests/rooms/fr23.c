#include "path.h"
inherit "/std/outside";

void setup() {

  set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

  set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   This forest is softly and gently calm.   There is an aura of "
"magic set about it.  Truly impressive trees are a part of the landscape, "
"towering many feet into the air.  There is the sweet scent of pine in the "
"air.  Shimmering flowers clump along the forest bed.  The path continues "
"to the northeast and southeast.\n\n");
#include "forest.d"

   add_property("no_undead",1);
  add_clone(NPCS+"animals.c", random(3));
  add_exit("northeast", HERE+"fr24.c", "path");
add_exit("southeast", HERE+"fr22.c", "path");
}

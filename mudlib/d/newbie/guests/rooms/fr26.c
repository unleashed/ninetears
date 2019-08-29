#include "path.h"
inherit "/std/outside";

void setup() {

   set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

  set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   This trail leads deeper into the Southern Forest.  It carries "
"you south, deeper into the magical forces that surround this area.  "
"From here, Unicorn Mountain seems to be very close now.  Still, much "
"lies in this forest that is yet to be seen.\n\n");
#include "forest.d"

   add_property("no_undead",1);
  add_clone(NPCS+"animals.c", random(3));
  add_exit("south", HERE+"fr25.c", "path");
   add_exit("southeast",HERE+"con03","path");
}

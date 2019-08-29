#include "path.h"
inherit "/std/outside";

void setup() {

  set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

  set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   The forest that surrounds you is vibrant and wild.  In the "
"distance you can see a mountain shaded a smoky blue.  There are only two "
"ways that you can leave, northwest and northeast.\n\n");
#include "forest.d"

   add_property("no_undead",1);
  add_clone(NPCS+"animals.c", random(3));
add_exit("northwest", HERE+"fr23.c", "path");
add_exit("northeast", HERE+"fr21.c", "path");
}

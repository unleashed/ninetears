#include "path.h"
inherit "/std/outside";

void setup() {

   set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

   set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   There have been many legends spread about the magic of this "
   "forest.  The bright greenery and cheerful sounds of birds in song "
   "make it seem so.  This road leads to the north towards Unicorn Cove "
   "and south towards the exit of the forest.\n\n");
#include "forest.d"

   add_property("no_undead",1);
  add_clone(NPCS+"animals.c", random(3));
   add_exit("north", HERE+"fr05.c", "path");
   add_exit("south", HERE+"con02.c", "path");
}

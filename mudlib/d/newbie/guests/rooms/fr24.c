#include "path.h"
inherit "/std/outside";

void setup() {

  set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

  set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
"   Here is a fascinating sight.  The plants and rocks here seem to "
"possess some very humanoid faces.  Some seem to have a friendly scowl, "
"whilst others grin quite cheerfully.  Wooden and stone eyes watch "
"expressively as the world passes them by.  The wind whispers through here "
"as if to give these immobile giants tongues and mouths with which to speak. "
" You may leave northeast towards the main road, or southeast or southwest "
"through the forest.\n\n");
#include "forest.d"


   add_property("no_undead",1);
  add_exit("northeast", HERE+"fr25.c", "path");
  add_exit("southwest", HERE+"fr23.c", "path");
  add_exit("southeast", HERE+"fr21.c", "path");
}

#include "path.h"
inherit "/std/outside";

void setup() {

   set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

   set_light(60);

   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   The magical forest stretches on before you.  You can feel the "
   "power needed to create this forest all around you.  The beautiful "
   "trees and shrubs seem to be kept well in order and the wildlife "
   "flourishes in this area.   A road lies to the east and the forest "
   "continues on to the northwest and to the southwest.\n\n");
#include "forest.d"


   add_property("no_undead",1);
  add_exit("east", HERE+"fr05.c", "path");
  add_exit("southwest", HERE+"fr22.c", "path");
  add_exit("northwest", HERE+"fr24.c", "path");
}

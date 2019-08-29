#include "path.h"
inherit "/std/outside";

void setup() {

   set_short("Unicorn Mountain : Southern Forest");

   set_zone("forest");

  set_light(80);

   set_long("\nUnicorn Mountain : Southern Forest\n\n"
     "    The forest around you is thick with life.  Between the trees "
"there is the flutter of bird wings and the movement of animals.  The green "+
"shadows seem to dance and play upon the forest floor.  \n");

 add_item("trees","The surrounding trees have leaves of the freshest green,"+
      " the green of spring. From among their branches you hear the sweet"+
      " songs of the innumerable birds in the forest, all singing in "+
      "celebration of life, beauty, and the Goddess Virga who protects "+
      "this realm and keeps it what it is.\n\n");

  add_item("birds","You can see them only as glimpses among the trees, but "+
      "you can hear their songs surround you and fill your soul with "+
      "joy.  The sheer beauty almost threathens to overcome you, and "+
      "you lose yourself in comtemplation for a few moments.\n");

   add_property("no_undead",1);
  add_exit("north", HERE+"fr26.c", "path");
  add_exit("southwest", HERE+"fr24.c", "path");
}



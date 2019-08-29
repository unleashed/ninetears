#include "path.h"
inherit "std/outside";
  void setup(){

   set_light(60);
   set_zone("forest");
   set_short("Unicorn Mountain : Southern Forest");
   set_long("\nUnicorn Mountain : Southern Forest.\n\n"
   "   As you continue your journey, you travel across a small stone path "
"over a bubbling brook that you come upon.  The forest that surrounds you "
"is quite peaceful.\n\n");
   add_item("brook", "This is a small, swift stream of water, splashing and "
                     "gurgling quite merrily as you cross.  A multitude of "
                     "bright and shiny rocks cover the stream's bed.\n");
   add_item("stone", "These stones are large enough to rest on the bottom of "
                     "the brook and allow a person dry passage across to the "
                     "other side.\n");
#include "forest.d"

   add_property("no_undead",1);
   add_exit("south", HERE+"fr04.c", "path");
   add_exit("west", HERE+"fr21.c", "path");


}

#include "path.h"
inherit "/std/outside";
void setup()
{
   set_light(85);
   set_short("Between Zones.");
   set_long("\nBetween Zones.\n\n"
      "   You are standing in an area between two completely different "
      "types of landscape. "
      "To the south you can see a dark forest, "
      "while to the north there is a desert. "
      "\n\n");
   add_exit("south",HERE+"ef1","path");
   add_exit("north",HERE+"bsand15.c","path");
   add_exit("east",HERE+"raiseroom","path");
   add_property("no_undead",1);
}


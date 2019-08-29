#include "path.h"
inherit "/std/outside";
void setup()
{
   set_light(85);
   set_short("Between Zones.");
   set_long("\nBetween Zones.\n\n"
      "   You are standing in an area between two completely different "
      "types of landscape. "
      "To the east you can see a sandy desert, "
      "while to the west there is a swamp. "
      "To the north lies a forest. "
      "\n\n");
   add_property("no_undead",1);
   add_exit("east",HERE+"bsand12","path");
   add_exit("west",HERE+"sw1.c","path");
   add_exit("north",HERE+"fr04.c","path");
}


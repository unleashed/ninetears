#include "path.h"
inherit "/std/outside";
void setup()
{
   set_light(85);
   set_short("Between Zones.");
   set_long("\nBetween Zones.\n\n"
      "   You are standing in an area between completely different "
      "types of landscape. "
      "To the south you can see a small village, "
      "while to the north there is a swamp. "
     "Eastward, you can see a dark forest, "
      "while to the west there seems to be a gate. "
      "\n\n");
   add_property("no_undead",1);
   add_exit("south",HERE+"street1","path");
   add_exit("north",HERE+"sw6.c","path");
   add_exit("east",HERE+"ef21.c","path");
   add_exit("west",HERE+"gate","path");
}


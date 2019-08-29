#include "path.h"
inherit "/std/outside";
void setup()
{
   set_light(85);
   set_short("Between Zones.");
   set_long("\nBetween Zones.\n\n"
      "   You are standing in an area between two completely different "
      "types of landscape. "
      "To the west you can see a sandy desert, "
      "while to the east there is a dark, gloomy area. "
      "Northwestward, you can see a relatively cheerful-looking forest. "
      "\n\n");
   add_property("no_undead",1);
   add_exit("west",HERE+"bsand17","path");
   add_exit("east",HERE+"den01.c","path");
   add_exit("northwest",HERE+"fr26","path");
}


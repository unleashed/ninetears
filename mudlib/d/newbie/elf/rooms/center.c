#include "path.h"

inherit "/std/outside";

#define NUM 2

void setup()
{
    set_light(80);
    add_property("no_undead",1); set_short("Realm of the Elf:  Center of Elven Village");
    set_long("\n   Realm of the Elf:  Center of Elven Village.\n\n"
      "     You are deep into the High Forest.  "
      "This looks like a peaceful well guarded part of "
"the forest. The elves must really take care of this part of the "
      "forest, and keep it free of goblins and other pests.\n"
      "     The air is filled with smells of "
      "grass and flowers. You hear birds singing their praise to nature."
      "  Hidden all around you in the forest lies a small elven "
      "village.  Only your keen elven eyesight allows you to spot "
      "the 'buildings' around you.  A path leads into the forest "
      "to the east."
      "\n\n");

    add_exit("southwest",ROOM+"shop.c","door");
    add_exit("east", ROOM+"fo10", "road");
    add_exit("west", ROOM+"forestinn", "door");
    add_exit("north", ROOM+"treant", "road");
    add_exit("south", ROOM+"raiseroom", "door");
    add_exit("northwest", ROOM+"guild", "door");

    add_item("buildings", "These buildings are nestled in trees "
      "all around you.\n");
    add_item("forest", "The forest seems to be inhabited by lots of wildlife. "
      "Everywhere you look, you see small animals moving.\n");
    add_item(({"wildlife","animals"}),"The creatures that scurry about are "
      "difficult to see because of the forest's coverage.  Besides, most are "
      "too small to take proper note of.\n");

    set_zone("track");
}

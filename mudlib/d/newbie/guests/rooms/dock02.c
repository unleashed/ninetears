/*  Code and file added by Grimbrand 10-9-94
*/



#include "path.h"
inherit "/std/outside";

void setup() {

    set_light(100);

    set_short("Belgar's Haven:  Central Section, Main Dock");

    set_long("\nBelgar's Haven:  Main Dock.\n\n"
      "   You have come to the main dock of Belgar's Haven.  It is here "
      "that the main dock connects to the piers that once served as the "
      "primary point of commerce and the lifeblood of Belgar's Haven.  Even "
      "the largest ships could dock upon the piers if the need arose.  "
      "While trade slipped in the recent years, the town "
      "council just rebuilt the central pier to accomadate "
      "an influx of private shipping.\n");

    add_property("no_undead",1);
    add_exit("east", HERE+"street3", "path");


    add_item(({"pier", "piers", "dock", "docks"}),
      "   The docks and piers are made of wood, of course, and cover this area "
      "thickly. You can see that they are in fair shape, but already "
      "some have fallen by the wayside due to disuse.\n");

    add_item("boats",
      "   The boats are few and far between, and are just small fishing vessels. "
      "There are none of the larger cargo ships, as there should be in a town "
      "like this one.\n");

    add_clone(NPCS+"man.c",1);
    set_zone("town");
}


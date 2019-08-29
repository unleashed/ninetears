/*  Code for western exit added by Grimbrand 10-9-94
*/


#include "path.h"
inherit "/std/room";

void setup() {
   object board;
    set_light(100);
    set_short("Market Street");
    set_zone("town");
    add_property("no_undead",1);
    set_long(
      "You are on a wide street in the small coastal town of Belgar's "
      "Haven. The street is paved with dirt, and you can tell that it is "
      "well worn, for there are deep ruts where the wheels of wagons pass "
      "through here. However, there don't seem to be any wagons now. The "
      "town is a quiet place now. There is none of the bustling about that "
      "you would expect in a town, even one this small. You don't even see "
      "many people here...it seems like the town of Belgar's Haven is on "
      "its last legs, and dying. "
      "You can see that this part of the street leads West to the town docks, "
      "and East to the Intersection. There is a shop of some sort to the "
      "South, with a large board across its frontage, "
      "and a large complex to the North. It appears "
      "to be a large shipyard, once full of bustle, but now eerily silent.\n");

    add_item(({"parchment","note","paper"}),
      " The note fades in parts, but seems to read:  "
      "in harbour.  We hope to reopen upon the god's pleasure.\n");

    add_exit("east", HERE+"intersection", "path");
    add_exit("west", HERE+"dock02.c", "path");

    add_item("street", 
      "The street is dirt-paved and worn, although most of the tracks are "
      "old. It doesn't see much use anymore.\n");
    add_item("people",
      "You can't see any people on the road here right now.\n");
    add_item("shop", 
      "The store you see to the South is a ramshackle collection of just "
      "about everything you can think of. The etuff is haphazardly piled "
      "outside, and you can only guess as to what it looks like inside.\n");
    add_item(({"training hall", "hall", "guild", "barracks"}),
      "This large building looks to be a training hall and barracks. On the "
      "outside wall is painted, 'The Swords of Justice'. \n");
   board = clone_object("/obj/misc/board");
   board->move(this_object());
   board->set_datafile("playerinfo");
}

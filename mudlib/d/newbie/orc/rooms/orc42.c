/*** By Wonderflug ***/
/*** Yes, caught up in domain work for once. ***/
#include "path.h"
inherit CASTLE+"baseroom.c";

 void setup()  { ::my_setup();
set_short("Realm of the Orc:  Path up the Mountain");
set_long("\n   Realm of the Orc:  Path up the Mountain.\n\n"
         "     You are on a long, windy path leading up the side of "
  "a mountain.  The rocks are gouged and scored with horrendous looking "
  "claw marks, and the odd blood stain.  It seems some battles have taken place here. "
  "An old rusty, half broken sword lies half-buried by the side "
  "of the path.  The path winds northeasterly, toward the "
  "top of the mountain and the sinister-looking tower on top, "
  "and westwards back toward the town.\n\n");
set_light(40);

add_item("sword", "A remnant of a battle long ago, judging by the "
  "amount of rust on it.");
add_item("tower", "Far in the distance, you can make out several spires "
  "and what seems to be an evil-looking red light from the top of the tower.\n");
add_item(({ "marks", "gouges", "rocks" }), "Claw marks "
  "are all over the place, big gouges ripped out of the face of the "
  "rocks.\n");
add_item(({ "bloodstains", "blood", "stains" }), "From the amount of old, "
  "dried blood caked to the rocks around here you'd guess a fairly "
  "major battle, or perhaps several smaller skirmishes, have taken place here.\n");
add_exit("west",CASTLE +"orc41","path");
add_exit("northeast",CASTLE +"orc40","path");
}

#include "path.h"
inherit "/std/room.c";

void setup() {
    set_short("Realm of the Orc:  Guard Barracks");
    set_light(40);
    set_long("\n   Realm of the Orc:  Guard Barracks.\n\n"
      "     This was obviously the barracks for the guards that "
      "once lived here.  "
      "You see two beds that are now in "
      "shambles.  Between the two beds you see some decayed "
      "remains of a corpse.  It looks as if this corpse is "
      "that of one of the guards that used to protect this "
      "castle.  To the south of here is a door that leads to "
      "the remainder of the dungeon.\n\n");
    add_item("bed","More of a cot then a bed, they are very "
      "old and dusty.\n");
    add_item("corpse","It looks like something has been eating on it.\n");
    add_clone(CHAR+"goul.c",1);
    add_property("no_undead",1);
    add_exit("south",DUNGEON +"dungeon08","door");
}

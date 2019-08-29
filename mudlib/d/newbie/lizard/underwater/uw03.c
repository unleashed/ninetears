#include "path.h"
inherit "/std/room";
void setup(){
    set_light(50);
set_short("Realm of the Lizard:  Underwater");
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     You have come to the edge of what appears to be some sort of"
             " ancient underwater civilization.  There are what appears to"
             " be, decayed buildings all to the west and southwest.  There"
                  " are also many fish swimming through these decayed"
                  " structures.\n");
    add_item(({"strucures", "buildings", "decayed buildings"}), "These"
             " old buildings look like they may have been fine"
             " craftsmanship at one time, but age has caught up with. "
             " Now they are only suitable for the fishes.\n");
    add_item("fish", "It appears the fish have takenover what was left"
             " of this place.\n");
    add_exit("southeast", UWATER+"uw02", "path");
    add_exit("south", UWATER+"uw04", "path");
    add_exit("southwest", UWATER+"uw08.c", "path");
    add_exit("west", UWATER+"uw07.c", "path");
    add_exit("northwest", UWATER+"uw06.c", "path");
}

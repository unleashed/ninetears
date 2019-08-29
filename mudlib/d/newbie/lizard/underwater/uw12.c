inherit "/std/room";
#include "path.h"
void setup(){
    set_light(45);
set_short("Realm of the Lizard:  Underwater Tunnel");
set_long("\nRealm of the Lizard:  Underwater Tunnel\n\n"
	 "     As you swim along in this tunnel, you notice it is a bit"
             " brighter here.  Maybe there is a light at the end of the"
             " tunnel after all.  Hopefully it is close.  There are a few"
             " small colorful fish swimming around here.\n");
    add_item("fish", "There are colorful fish swimming all around.  They"
             " may be small, but they sure can be irritating.\n");
    add_exit("south", UWATER+"uw11.c", "path");
    add_exit("north", UWATER+"uw13", "path");
}

#include "path.h"
inherit "/std/room";
void setup(){
set_short("Realm of the Lizard:  Underwater");
set_light(50);
set_long("\nRealm of the Lizard:  Underwater\n\n"
	 "     You have plunged into this lake.  It is awfully cold in this"
             " water.  As you slowly get the hang of swimming you make your way"
             " to the west.  You notice lots of underwater plant and animal"
             " life.  Off to the south you see what appear to be the remains"
             " of some kind of shack that was built too close to the waters"
             " edge.\n");
    add_item(({"plant", "plant", "plantlife"}), "There are many different"
             " types of plant life down here.  Amazing how different it is"
             " down here than it is on the surface.\n");
    add_item(({"animals", "animal", "animal life"}), "There are many"
             " different type of fishes down here.  Try as you may, you"
             " never could catch these whoppers when you used a pole.\n");
    add_item("shack", "This appears to be a rough shack that was enveloped"
             " by the lake.  Some lizard man was not very smart when he"
             " built that shack.\n");
    add_exit("west", UWATER+"uw02.c", "path");
    add_exit("up", "/d/newbie/lizard/rooms/lizard12.c", "path");
}

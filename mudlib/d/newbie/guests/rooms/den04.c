#include "path.h"
inherit "/std/room";

void setup() {
set_light(50);
set_short("City of Dendall:  Cavern");
add_property("no_undead",1);
set_long("\nCity of Dendall:  Cavern\n\n"
    "    You are in the back alley of Grock's weapons shop.  Garbage is "
	 "strewn every where you look.  You even think you see a rat scurry "
	 "from one pile of trash to the other, then you happen to notice "
	 "another rat.  There are quite a few rats now that you look.  To "
	 "the southeast you believe that you hear the banging of a hammer "
	 "against an anvil.\n\n");
add_item("garbage","As you look around, you see mounds of garbage "
	 "along the eastern wall and stacks of boxes on the "
	 "western one.  You guess that the Duergar don't have "
	 "a very effective waste system.\n");
	 
add_clone(NPCS+"rat.c", 3);	 
add_exit("west", HERE+"den06", "road");
set_zone("dendall");
}

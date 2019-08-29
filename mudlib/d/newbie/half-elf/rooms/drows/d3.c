//Ljen nov -96

inherit"/std/room";
#include "path.h"
object drow;

void setup()
{
   set_light(50);

   set_short("Drow tunnel");

   set_long(" You can hear the water drip slowly down the"
            " walls of this tunnel, and you can also hear the rats"
            " sneak around. But the most excruciating sound is the"
	    " moans and howls of pain you faintly can hear from the east."
            " The presence of evil feels even stronger here, but it seems"
            " like it comes from the east somehow."
	    " There is a small tunnel leading northeast up to a kind" 
	    " of crossing, hard to see in this gloom though.\n");

   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");


   add_clone(NPC+"drow.c", 1);

   add_exit("west", DROWS+"c3.c", "path");

   add_exit("northeast", DROWS+"e2.c", "path");


}


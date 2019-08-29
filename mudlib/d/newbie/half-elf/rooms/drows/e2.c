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
	    " There is a small tunnel leading southeast into even" 
	    " deeper and darker caves.. \n");

   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");


   add_clone(NPC+"drow.c", 1);

   add_exit("west", DROWS+"d2.c", "path");

   add_exit("southeast", DROWS+"f3.c", "path");

   add_exit("northeast", DROWS+"f1.c", "path");

   add_exit("southwest", DROWS+"d3.c", "path");

}


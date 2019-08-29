//Ljen nov -96

inherit"/std/room";
#include "path.h"
object drow;

void setup()
{
   set_light(50);

   set_short("Drow tunnel");

   set_long(" The narrow tunnel continues, but the sound is getting"
	    " louder and louder. From here you can see a vague light"
 	    " to the south. It sounds like the screaming comes from"
	    " there too. The drows in here are not too happy that you"
	    " are poking around in here. Seems like there is something"
	    " here they are desperate to defend.. \n");


   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");



   add_clone(NPC+"drow.c", 2);

 
   add_exit("south", DROWS+"h3.c", "path");

   add_exit("west", DROWS+"g2.c", "path");


}


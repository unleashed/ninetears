//Ljen nov -96

inherit"/std/room";
#include "path.h"
object drow;

void setup()
{
   set_light(50);

   set_short("Drow tunnel");

   set_long(" The narrow tunnel continues, but the sound is getting"
	    " louder and louder. Now the light is clearer. It is coming"
 	    " from what seems to be a cave to the west."
	    " Now you can clearly hear that the scream comes from in there."
            " The drows in here are not too happy that you"
	    " are poking around in here. Seems like there is something"
	    " here they are desperate to defend.. \n");


   add_item("wall", "You can't see much, but it seems like they are of"
            " some kind of black rock. Water is dripping slowly down.\n");



   add_clone(NPC+"drow.c", 1);

 
   add_exit("north", DROWS+"h2.c", "path");

   add_exit("west", DROWS+"g3.c", "path");


}


//modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun - Hall");
   set_long("The hall of the castle is a big room with four exits, two to "
            "the hallways, one out the gate, and one leading in to the"
	    " great castle. The walls are all decorated "
            "with tapestries that show the way of life of the first half elven "
            "people in the realms.  In each corner there is one torch which "
            "lights up the room.\n");

   add_item("tapestries", "Large tapestries hanging down from the roof.\n");

   add_item("tapestry", "Large tapestries hanging down from the roof.\n");
   
   add_item("torch", "A common torch with a wooden haft and a cloth head "
                     "soaked in oil\n");

   set_light(50);

   add_exit("north",  CAST+"e3.c", "door");
   add_exit("south", CAST+"e5.c", "door");
   add_exit("east", CAST+"f4.c", "door"); 
   add_exit("west", CAST+"d4.c", "door");
}


    

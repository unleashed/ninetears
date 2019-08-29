// Modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun: Leeds Bedroom.");
   set_long("The room you are in is decorated with war items of all kinds. "
            "Old broadswords, axes and spears are all hanging down "
            "from the ceiling and the walls. Some of these belonged to Leeds' "
            "enemies, other to his friends that now have passed away. "
            "Leeds is proud of them all, and they help him when he sits down "
            "to remember his life and the significance of it. In the southeast "
	    "corner there is a big bed and at the north wall a chimney "
	    "carved in the rock. It is lighted, warming the room and "
	    "giving light.\n");

   add_item("chimney", "Carved in the rock.\n"),

   add_item("bed", "The Commander prefers hard beds, so he sleeps on a "
                   "rock bed, made escpecially for him.\n");
   add_item("walls", "You can't see the walls for all the weapons hanging"
	    " around. \n");

   add_item("ceiling", "Banners, weapons and all sorts of equipment hangs"
	    " here. But all of it is old, and of no use for a young"
            " adventurer as yourself.\n"); 

   set_light(50);

   add_exit("east", CAST+"e2.c", "door");

}

    

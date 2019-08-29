//Modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun - Freezer");
   set_long("The freezer of the kitchen is a little room with a permanent"
	    " cold spell cast on it.  Inside you see several vegetables"
            " completely freezed but not much meat.  The illumination of" 
            " the place comes from the ceiling itself, which radiates" 
            " soft light in all directions giving a good view of the food"
            " it cointains.\n");

   add_item("vegetables","These vegetables and fruits come from the nearby "
                         "town in the jungle\n");

   add_item("food", "Frozen food, stored here to be used later.\n");

   set_light(50);

   add_exit("south",     CAST+"a4.c",  "door");
}

    

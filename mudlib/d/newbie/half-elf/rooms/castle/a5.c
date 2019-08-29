//Modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun - Kitchen");
   set_long("This is the kitchen of the castle.  The kitchen is a big room :"
            "at the east wall there are the stoves, obviously used to "
            "cook on. At the west wall there is a huge sink "
            "where the staff clean the food, and the cook (unknown to the " 
            "rest of the castle) takes his morning bath. "
	    "The storeroom is further north, through a open door.\n");

   add_item("torch", "A common torch with a wooden haft and a cloth head "
                     "swet in oil\n");
   add_item("sink", "An large sink, with plenty of room for a bath,"
	    " even for a large man like the cook.\n");

   add_item("stoves", "Big cosy stoves to cook their food on, they seem"
	    " like they are often in use.\n");


   set_light(50);

   add_clone(NPC+"cooker",1);

   add_exit("north", CAST+"a4.c",   "door");
 
}

    

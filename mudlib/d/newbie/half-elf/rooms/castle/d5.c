// Modified by Ljen okt -96
//Coded by Joram on the 16th of September '96

inherit "/std/room";
#include "path.h"


void setup(){
   set_short("Castle Of The Green Sun: Bedroom");
   set_long("The most disordered room and most filthy is the chamber of"
            " the castle cook.  You can't see the bed, because clothes"
	    " are scattered all over it. The floor is the same, but the "
            "clothes have to fight with scraps of food to win a place on"
	    " it.  The walls have a peculiar decoration, an odd  mix"
            " consisting of old soup, something you think is salad, and"
	    " other various pieces of food. The oven to the "
            "north it should give light and warm the room, but is has" 
            " instead been used to cook on."
            " The smell in here is devastating, sweat, burned food and"
	    " something that you can't make out. It makes you sick though.\n");

   add_item("oven", "Carved in the rock, purposed to warm the room, "
	             " but have been used to cook food on instead.\n");
   
   add_item("bed", "You _think_ there might be a bed under there somewhere"
	    " but you dare not be certain..\n");

   add_item("walls", "This must surely be some sort of new art, because"
	    " it is decorated in a strange fashion."	
            " Seems like the cook have gone completely berserk in here"
	    " with whatever he had as leftovers from dinner.\n");

   add_item("food", "It might have been food sometime, but now it is just"
	    " a badsmelling jelly kind of substance."
	    " This is _really_ no a nice place to be.\n");


   set_light(50);

   add_exit("east",    CAST+"e5.c",   "door");
}

    

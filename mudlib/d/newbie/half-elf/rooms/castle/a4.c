//Modified by Ljen okt -96
//Coded by Joram on the 12th of September '96

inherit "/std/room";
#include "path.h"

void setup(){
   set_short("Castle Of The Green Sun: Storeroom");
   set_long("This is the storeroom of the castle, with food of all kinds"
            " covering the walls. The shelves are loaded with meat,"
            " potatoes and almost all the food you can imagine."
            " On the north wall, you can see a small door with the" 
            " sign : 'Freezer' on it.\n");

   add_item("meat", "Meat of sheep, cow and even whale!\n");

   add_item("potatoes", "Small potatoes, large potatoes, brown potatoes."
			" Probably enough potatoes here to feed an whole"
	      		" army.\n");
   add_item("food", "All sorts of food that you could imagine."
	    " Most of it must be brought from the nearby village.\n");

   add_item("shelves", "Large shelves loaded with food.\n");   

   set_light(50);


   add_exit("south", CAST+"a5.c",   "door");
   add_exit("east", CAST+"b4.c", "door");
   add_exit("north", CAST+"a3.c",   "door");
}

    

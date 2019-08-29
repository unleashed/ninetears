#include "path.h"

inherit "/std/room.c";

void setup()
 {
    set_short("Guardpost");

    set_long("Village guardpost.\n\n"
        "     As you stand in the always manned guardpost you get "
	"a sight over the wide area habited by the elves. You even "	
	"notice a small group of houses down the river to the "
	"southeast. "
	"Here every movement of the forest get watched by the "
	"highly skilled scouts of the village. The guardpost " 	
	"is one of the places set out for the villagers common "
	"saftey and is always manned with atleast four sharp viewing "
	"eyes.\n\n");
 
    set_light(80);
   
	// should add an NPC later
    add_item("window","      \n");   
   
    add_smell(({"room","air"})," You smell here nature "
	"and only nature in its current season.\n");
               
        
    add_exit("west",ROOMS+"F3.c","door");	
    add_exit("down",ROOMS+"y5.c","door");
    
  
   }
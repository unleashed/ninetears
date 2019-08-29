#include "path.h"

inherit "/std/room.c";

void setup()
 {
    set_short("Stockroom");

    set_long("Village stockroom.\n\n"
        "     Before you lies the food and materials commonly "
	"stocked by the villagers. Here lies all that is needed "
	"for the everyday life of the elves, including arms and "
	"armours for hunt and defense of life and home. "
	"There is an elven male guarding and assorting the "
	"goods."
	"The stockroom continues up by the stairs."
	"\n\n");
 
    set_light(80);
  
    add_smell(({"room","air"}),"A fresh smell streams from the open "
	"windows adding some of the natures aroma. \n");
               
        
    add_exit("east",ROOMS+"v5.c","door");	
    add_exit("west",ROOMS+"t5.c","door");
    add_exit("up",ROOMS+"F5.c","door");
  
   }
#include "path.h"

inherit "/std/room.c";

void setup()
 {
    set_short("Stairs");

    set_long("Stairs down.\n\n"
        "Here are the stairs down to the ground mostley used by "
	"the elven villagers to get up to their homes. They are "
	"as everything else elven and made in wood, exceptional "
	"craftsmanship and certainly made with artistic sence as "
	"it gives its user a safe and light route down."
	"\n\n");
 
    set_light(80);
   
    add_item("window","Looking through the open window to the south "
	"you see the forest surrounding the elven village.    \n");   
   
    add_smell(({"room","air"}),"A fresh smell streams from the open "
	"windows adding some of the natures aroma.\n");
               
        
    add_exit("northwest",ROOMS+"t7.c","door");	
    add_exit("northeast",ROOMS+"y7.c","door");
      
   }
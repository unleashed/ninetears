#include "path.h"

inherit "/std/room.c";

void setup()
 {
    set_short("elven house");

    set_long("Elven treehouse.\n\n"
        "     You've entered a smaller house built high up in "
	"the trees of the elven village. All around you in "
 	"the room's furniture you notice beautiful carvings showing " 
	"different forms of the nature spirits praised by the elfs."        
	"\n\n");
 
    set_light(80);
   
    add_item("window","Looking through the westward open window you "
	"see the forest surounding the elven village. Just below "
	"to the right you see a small hut looking like a temple with " 
	"the walls filled with strange carvings. To the left you "
	"notice a big majestetic oaktree.   \n");   

    add_item("carvings","There are serveral astonishing forms of "
	"many different animals of the forest. They seem to be "
	"carved in a special order beginning with a Deer and a Cat "
	"and ending with a pig and a dragon.  \n");
   
    add_item("furniture","The furniture of the room consists of. "
	"a wonderfully carved table with chairs having the shape "
	"of a tree, with a hollow crown as seat and support. In each "
	"corner of the room there lies a lower wooden desk with "
	"some fresh moss and leaves on it. Most likely the relaxing "
	"place of elfs. \n");
  
    add_smell(({"room","air"}),"A fresh smell streams from the open "
	"windows adding some of the natures aroma.\n");
               
        
    add_exit("north",ROOMS+"t3.c","door");	
    add_exit("south",ROOMS+"t7.c","door");
    add_exit("down",ROOMS+"f5.c","door");  
   }
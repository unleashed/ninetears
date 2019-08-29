#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       After a whiles following of the path you slowly "
	"leave the area of the elven village. You notice some " 
	"more different animals and that the river continues " 
	"southeastwards. Its blank and glittering surface still
	"creates an amazing view, added to that are the, here,
	"more active fishes.  \n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The surrounding nature "
	"forms sweet shapes all along the calmly flowing river. "
	"Here small bushes perfectly unite with larger prouder trees.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   

	add_exit("northwest",ROOMS+"j5.c","path");
	add_exit("southeast",ROOMS+"o10.c","path");	        
	
   }
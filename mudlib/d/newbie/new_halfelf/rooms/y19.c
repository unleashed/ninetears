#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       The glittery river leads on towards the village in "
	"the southwest and there makes a turn to the south. "
	"The village to the southwest carries some sort of emptyness. "
	"Nowere you see any people, just some rats and mongrels "
	"sniffing around by the houses. The fisher path is coming "
	"to an end it seems. But the river bank look rather easy "
	"and joins the area of the village further southeast. "
	"\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The surrounding nature "
	"forms sweet shapes all along the calmly flowing river. "
	"Here small bushes perfectly unite with larger prouder trees.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   


	add_exit("northwest",ROOMS+"u16.c","path");
	add_exit("southeast",ROOMS+"A21.c","path");	        
	
   }
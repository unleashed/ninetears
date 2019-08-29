#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       You've reached a point now, where nothing but "
	"the birds and fishes can be heard. Now and then though, "
	"you notice quiet murmors coming from the woods, might "
	"be a bear.    In the middle of the river lies a little "
	"sandbank which seems reachable with a leap. On it you notice " 
	"some kind of stick.    The river goes on to the southeast.\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The surrounding nature "
	"forms sweet shapes all along the calmly flowing river. "
	"Here small bushes perfectly unite with larger prouder trees.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   

	add_exit("northwest",ROOMS+"m8.c","path");
	add_exit("southeast",ROOMS+"q12.c","path");	        
	
   }
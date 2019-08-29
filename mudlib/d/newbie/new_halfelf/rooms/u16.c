#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       The blank and glittering water of the river "
	"continues from here against a couple of huts and cabins."
	"Actually looks as a smaller village from here, but without."
	"that much of activity. There's a path to west from here
	"coiming from the woods.    Insects seems to be waiting for you "
	"to settle, as they slowly gather behind you.  You hear no "
	"twitters from the birdies and no activity by any fishes, "
	"all seems calm. "
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

	add_exit("west",ROOMS+"q16.c","path");
	add_exit("northwest",ROOMS+"s14.c","path");
	add_exit("southeast",ROOMS+"y19.c","path");	        
	
   }
#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       Silverbreed, still granting a incredible view, "
	"continues from here against what you think looks like "
	"a human village. You see a couple of huts and cabins "
	"along the river but not that much of activity. As standing " 
	"on light swarms of insects begin to gather around you. "
	"You don't understand why, but the happy twitters of the "
	"birdies has ceased and even the wild activity of the "
	"fishes is no longer seen.\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The surrounding nature "
	"forms sweet shapes all along the calmly flowing river. "
	"Here small bushes perfectly unite with larger prouder trees.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   


	add_exit("northwest",ROOMS+"q12.c","path");
	add_exit("southeast",ROOMS+"u16.c","path");	        
	
   }
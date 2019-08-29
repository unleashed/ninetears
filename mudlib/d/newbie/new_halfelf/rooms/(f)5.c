#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Clearing by river");

    set_long("Clearing by river.\n\n"
        "       You stand on the banks of Silverbreed. It's the "
	"lifegiving river sharing its food and water with the "
	"elves. Here lies the centre of their daily work and "
	"activities. From here you see a hut behind a big old "
	"oak to the west. You also notice a small path following "
	"the stream of Silverbreed to the west. \n\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The trees are huge, "
	"massive oaks standing steady on the ground. They give "
	"the village plenty safety just by their looks.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   

	add_item("hut"," xxx\n")

	add_exit("north",ROOMS+"f3.c","path");
	add_exit("south",ROOMS+"f7.c","path");	        
	add_exit("east",ROOMS+"j5.c","path");	
	add_exit("west",ROOMS+"d5.c","path");	     
   }
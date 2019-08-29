#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Clearing by river");

    set_long("Clearing by river.\n\n"
        "       Standing on the banks of Silverbreed you get
	"confronted with a steady flowing beauty. Its surface
	"displays a wonderful mix of the forest's colours." 
	"Here you see people in their daily work and most "
	"oftenly quite merry faces. The Silverbreed turns "
	"a bit here to the southeast, making it hard to see "
	"downwards the river.\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The trees are huge, "
	"massive oaks standing steady on the ground. They give "
	"the village plenty safety just by their looks.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   


	add_exit("north",ROOMS+"j3.c","path");
	add_exit("south",ROOMS+"j7.c","path");	        
	add_exit("southeast",ROOMS+"m8.c","path");	
	add_exit("west",ROOMS+"f5.c","path");	     
   }
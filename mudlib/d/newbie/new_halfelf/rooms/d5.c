#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Large Oak Tree");

    set_long("Large Oak Tree.\n\n"
        "       Infront of you climbs a big oaktree. Its wide set "
	"of branches and massive trunk gives you an old and steady "
	"impression. You try to measure its base but end up short of "
	"armlength. The tree's trunk actually looks as a fair challange "	
	"for a curious climber and even offers some helpfull branches "
	"on the way. The Silverbreed's water pours in from east where "
	"you also notice a small hut.\n\n");
 
    set_light(80);
   
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the "
	"glitter seems to come from the fishes idling around in the "
	"water. \n");   

	//add_item("hut"," xxx\n")

	add_exit("up",ROOMS+"r5.c","path");
	add_exit("east",ROOMS+"f5.c","path");	
	add_exit("west",ROOMS+"b5.c","path");
   }
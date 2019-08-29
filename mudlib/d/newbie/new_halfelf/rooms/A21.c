#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Center of Human Village");

    set_long("Center of Human Village.\n\n"
        "       You've entered the human village. Perhaps not "
	"the most habited, but still with a Tavern and a Shop, "
	"to the south and east. To the west stands a cabin from "
	"where you actually see smoke from the chimney. The village "
	"has been situated by the river and stands clear without any "
 "trees. As the river continues southwest, so does a path, "
	"both along Silverbreed, and to the southeast. A wider trail goes "
	"northeast with the tracks of a wagon. "
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

	add_item(({"cabin","house","hut"}),"   Most of the houses, "
	"which almost includes everyone of them, are built with no "
	"care for their looks. The one to the west is the only with "
	"some extra work spent on. Not only its red paint, but also "
	"the wonderfully carved door."

	add_exit("west",ROOMS+"y21.c","door");
	add_exit("east",ROOMS+"C21.c","door");
	add_exit("south",ROOMS+"A23.c","door");
	add_exit("northwest",ROOMS+"y19.c","path");
	add_exit("northeast",ROOMS+"C19.c","path");
	add_exit("southwest",ROOMS+"y23.c","path");	        
	add_exit("southeast",ROOMS+"E25.c","path");
   }

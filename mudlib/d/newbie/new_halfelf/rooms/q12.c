#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Path by Silverbreed");

    set_long("Path by Silverbreed.\n\n"
        "       The river as the fishers path goes on to the "
	"southeast here. Here the trees grow with a little more "
	"space between them.    To the west you see another path "
	"leading into the woods. It's clearly not of elven kind. "
	"And directly by its start you see some old fragments of "
	"a deerskin. "
	\n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The surrounding nature "
	"forms sweet shapes all along the calmly flowing river. "
	"Here small bushes perfectly unite with larger prouder trees.\n");   
	 
	add_item("river","     Silverbreed is the centre of life " 
	"among these elvens. Its calm and glittering flow sure "
	"gives you a hint of the source for its name. Some of the 
	"glitter seems to come from the fishes idling around in the"
	"water. \n");   

	add_item("path","It seems to be some clumsy hunters path 
	"as broken branches and leaves lies all over it. "
	
	add_exit("southwest",ROOMS+"o14.c","path");
	add_exit("northwest",ROOMS+"o10.c","path");
	add_exit("southeast",ROOMS+"s14.c","path");	        
	
   }
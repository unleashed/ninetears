#include "path.h"
inherit "/std/outside.c";

void setup()
 {
    set_short("Forrest Path");

    set_long("Forrest Path.\n\n"
        "       All around the path stand the trees tall and
	"proud. Its surrounded by small flower and other wildly 
	"grown plants. But as it just begun, it also ends. To the south 
	"lies now a totally bloomed meadow, with butterflies of 
	"almost every imaginable colour combination. \n");
 
    set_light(80);
   
	add_item(({"tree","trees"}),"     The trees are of mixed "
	"type. Here and there stand an oak, making it all seem "
	"majestetic.\n");   
	 
	add_item("river","     Silverbreed now turns into a massive "
	"over grown area of the forest and disappears into the jungle.\n");   

	add_exit("south",ROOMS+"y25.c","door");
	add_exit("northeast",ROOMS+"A21.c","path");
	
   }
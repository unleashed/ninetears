#include "path.h"
inherit "/std/room";


void setup() {
	set_short("Snaga's Equipment Shop");
	set_long("This is the storeroom for Snaga's Equipment "
		"shop.  There are several items on the shelves here.  "
		"\n\n");

   add_exit("out",TOWN+"town01.c","door");
   set_light(60);
}

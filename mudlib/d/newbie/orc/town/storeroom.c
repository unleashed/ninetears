#include "path.h"
inherit "/std/room";


void setup() {
	set_short("Shagrat's Equipment Shop");
	set_long("This is the storeroom for Shagrat's Equipment "
		"shop.  There are several items on the shelves here.  "
		"\n\n");

  add_exit("shop",TOWN+"town09.c","door");
   set_light(60);
}

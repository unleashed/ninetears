#include "path.h"
inherit "/std/room";


void setup() {
	set_short("Parham's Smelly Shop");
	set_long("This is the storeroom for Parham's Equipment "
		"shop.  There are several items on the shelves here.  "
		"\n\n");

   add_exit("out",VALLEY+"gnome18.c","out");
   set_light(60);
}


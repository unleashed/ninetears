#include "path.h"
inherit "/std/room";


void setup() {
	set_short("Zundrin's Equipment Shop");
	set_long("This is the storeroom for Zundrin's Equipment "
		"shop.  There are several items on the shelves here.  "
		"\n\n");

   add_exit("out",ROOM+"dwarf30.c","out");
   set_light(60);
}

#include "path.h"
inherit "/std/room";


void setup() {
	add_property("no_undead",1); set_short("Cirrion's Equipment Storeroom");
	set_long("This is the storeroom for Cirrion's Equipment "
		"shop.  There are several items on the shelves here.  "
		"\n\n");

   add_exit("out",ROOM+"shop.c","out");
   set_light(60);
}

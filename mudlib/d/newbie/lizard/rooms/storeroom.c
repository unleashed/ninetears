#include "path.h"
inherit "/std/room";


void setup()
{
	set_short("Darklor's Smithy");
     set_long("This is the storeroom for Darklor's Smithy.  There "
		"are weapons and armors lining the walls.\n\n");

   add_exit("out",ROOM+"smithy7.c","out");
   set_light(60);
}

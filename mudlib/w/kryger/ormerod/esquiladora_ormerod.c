inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Esquiladora%^RESET%^.");
	set_long(query_short()+"\n"+ESQUILADORA".\n\n");
    add_property("luz_real",50);
	add_exit("norte",ROOMORM"pueblo_ormerod_3.c","door");
}
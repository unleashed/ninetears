inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Matadero%^RESET%^.\n");
	set_long(query_short()+"\n"+MATADERO".\n\n");
    set_zone("pueblo_ormerod");
	add_exit("sudeste",ROOMORM"cruce_ormerod.c","door");
}
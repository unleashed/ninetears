inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	add_exit("norte",ROOMORM"corral_ormerod_8.c","standard");
	add_exit("noreste",ROOMORM"corral_ormerod_10.c","standard");
	add_exit("sur",ROOMORM"corral_ormerod_6.c","standard");
	add_exit("sudeste",ROOMORM"camino_ormerod_16.c","standard");
}
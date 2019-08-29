inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	add_exit("norte",ROOMORM"camino_ormerod_10.c","road");
	add_exit("noroeste",ROOMORM"corral_ormerod_3.c","standard");
	add_exit("sur",ROOMORM"corral_ormerod_4.c","standard");
	add_exit("este",ROOMORM"corral_ormerod_9.c","standard");
	add_exit("sudoeste",ROOMORM"corral_ormerod_2.c","standard");
}
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	add_exit("norte",ROOMORM"corral_ormerod_29.c","standard");
	add_exit("sur",ROOMORM"corral_ormerod_27.c","standard");
	add_exit("sudoeste",ROOMORM"corral_ormerod_21.c","standard");
	add_exit("noroeste",ROOMORM"corral_ormerod_22.c","standard");
}
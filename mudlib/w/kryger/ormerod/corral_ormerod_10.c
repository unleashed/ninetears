inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	add_exit("sudoeste",ROOMORM"corral_ormerod_7.c","standard");
	add_exit("oeste",ROOMORM"corral_ormerod_8.c","standard");
	add_exit("sudeste",ROOMORM"corral_ormerod_11.c","standard");
	add_exit("este",ROOMORM"corral_ormerod_12.c","standard");
}
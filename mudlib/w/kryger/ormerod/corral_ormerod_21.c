inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	add_exit("noreste",ROOMORM"corral_ormerod_28.c","standard");
	add_exit("este",ROOMORM"corral_ormerod_27.c","standard");
	add_exit("oeste",ROOMORM"corral_ormerod_16.c","standard");
}
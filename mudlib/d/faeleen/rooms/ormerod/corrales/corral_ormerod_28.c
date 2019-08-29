//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	set_exit_color("rojo_c");
	add_exit("norte",ROOMORMCO"corral_ormerod_29.c","standard");
	add_exit("sur",ROOMORMCO"corral_ormerod_27.c","standard");
	add_exit("sudoeste",ROOMORMCO"corral_ormerod_21.c","standard");
	add_exit("noroeste",ROOMORMCO"corral_ormerod_22.c","standard");
}
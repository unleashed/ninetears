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
	add_exit("sudoeste",ROOMORMCO"corral_ormerod_7.c","standard");
	add_exit("oeste",ROOMORMCO"corral_ormerod_8.c","standard");
	add_exit("sudeste",ROOMORMCO"corral_ormerod_11.c","standard");
	add_exit("este",ROOMORMCO"corral_ormerod_12.c","standard");
}
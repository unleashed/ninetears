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
	add_exit("sudoeste",ROOMORMCO"corral_ormerod_1.c","standard");
	add_exit("este",ROOMORMC"camino_ormerod_10.c","road");
	add_exit("sudeste",ROOMORMCO"corral_ormerod_5.c","standard");
}
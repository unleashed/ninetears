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
	add_exit("sudoeste",ROOMORMC"camino_ormerod_16.c","road");
	add_exit("noroeste",ROOMORMCO"corral_ormerod_10.c","standard");
	add_exit("norte",ROOMORMCO"corral_ormerod_12.c","standard");
	add_exit("este",ROOMORMCO"corral_ormerod_13.c","standard");
	add_exit("sur",ROOMORMC"camino_ormerod_17.c","road");
}
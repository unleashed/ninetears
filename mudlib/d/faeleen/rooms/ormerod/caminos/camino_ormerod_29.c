//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO1".\n\n");
	set_night_long(query_short()+"\n"+CAMINON1".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("red");
	add_exit("noroeste",ROOMORMC"camino_ormerod_27.c","road");
	add_exit("este",ROOMORMP"granja_c.c","standard");
	add_exit("noreste",ROOMORMCO"corral_ormerod_22.c","standard");
}
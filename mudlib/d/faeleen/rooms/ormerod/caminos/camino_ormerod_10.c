//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO2".\n\n");
	set_night_long(query_short()+"\n"+CAMINON2".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("red");
	add_exit("norte",ROOMORMC"camino_ormerod_11.c","road");
	add_exit("oeste",ROOMORMCO"corral_ormerod_3.c","standard");
	add_exit("sur",ROOMORMCO"corral_ormerod_5.c","standard");
	add_exit("sudeste",ROOMORMCO"corral_ormerod_9.c","standard");
	add_exit("sudoeste",ROOMORMP"granja_d.c","standard");
}
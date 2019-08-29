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
	add_exit("este",ROOMORMC"camino_ormerod_17.c","road");
	add_exit("oeste",ROOMORMCO"corral_ormerod_6.c","standard");
	add_exit("noreste",ROOMORMCO"corral_ormerod_11.c","standard");
	add_exit("noroeste",ROOMORMCO"corral_ormerod_7.c","standard");
	add_exit("norte",ROOMORMP"granja_a.c","standard");
}
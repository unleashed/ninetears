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
	add_exit("sudeste",ROOMORMC"camino_ormerod_24.c","road");
	add_exit("sudoeste",ROOMORMC"camino_ormerod_19.c","road");
}
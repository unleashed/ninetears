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
	set_exit_color("green");
	add_exit("norte",ROOMORMC"camino_ormerod_3.c","road");
	add_exit("sur",ROOMORMC"camino_ormerod_1.c","road");
	}
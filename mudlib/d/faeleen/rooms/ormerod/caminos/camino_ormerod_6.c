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
	add_exit("noreste",ROOMORMC"camino_ormerod_7.c","road");
	add_exit("sudoeste",ROOMORMC"camino_ormerod_5.c","road");
	}
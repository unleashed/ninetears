inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO1".\n\n");
	set_long_night(query_short()+"\n"+CAMINON1".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("green");
	add_exit("noreste",ROOMORM"camino_ormerod_6.c","road");
	add_exit("sur",ROOMORM"camino_ormerod_4.c","road");
	}
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO2".\n\n");
	set_night_long(query_short()+"\n"+CAMINON2".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("green");
	add_exit("norte",ROOMORM"camino_ormerod_5.c","road");
	add_exit("sudoeste",ROOMORM"camino_ormerod_3.c","road");
	}
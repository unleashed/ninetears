inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO1".\n\n");
	set_long_night(query_short()+"\n"+CAMINON1".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("red");
	add_exit("oeste",ROOMORM"camino_ormerod_25.c","road");
	add_exit("sudeste",ROOMORM"camino_ormerod_29.c","road");
	add_exit("este",ROOMORM"corral_ormerod_17.c","standard");
	add_exit("sur",ROOMORM"corral_ormerod_14.c","standard");
}
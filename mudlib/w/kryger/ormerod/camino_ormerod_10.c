inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO2".\n\n");
	set_night_long(query_short()+"\n"+CAMINON2".\n\n");
	set_zone("camino_ormerod");
	set_exit_color("red");
	add_exit("norte",ROOMORM"camino_ormerod_11.c","road");
	add_exit("oeste",ROOMORM"corral_ormerod_3.c","standard");
	add_exit("sur",ROOMORM"corral_ormerod_5.c","standard");
	add_exit("sudeste",ROOMORM"corral_ormerod_9.c","standard");
	add_exit("sudoeste",ROOMORM"granja_d.c","door");
}
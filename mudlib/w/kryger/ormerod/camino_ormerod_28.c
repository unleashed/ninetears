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
	add_exit("sudoeste",ROOMORM"camino_ormerod_26.c","road");
	add_exit("norte",ROOMORM"corral_ormerod_15.c","standard");
	add_exit("sudeste",ROOMORM"corral_ormerod_18.c","standard");
	add_exit("noreste",ROOMORM"granja_b.c","door");
	
}
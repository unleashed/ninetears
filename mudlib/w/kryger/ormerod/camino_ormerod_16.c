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
	add_exit("este",ROOMORM"camino_ormerod_17.c","road");
	add_exit("oeste",ROOMORM"corral_ormerod_6.c","standard");
	add_exit("noreste",ROOMORM"corral_ormerod_11.c","standard");
	add_exit("noroeste",ROOMORM"corral_ormerod_7.c","standard");
	add_exit("norte",ROOMORM"granja_a.c","door");
}
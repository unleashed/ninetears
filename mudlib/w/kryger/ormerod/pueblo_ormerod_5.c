inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Calle Principal %^RESET%^.");
	set_long(query_short()+"\n"+CALLEP".\n\n");
	set_night_long(quert_short()+"\n"+CALLEPN".\n\n");
	set_zone("pueblo_ormerod");
	add_exit("sur",ROOMORM"carniceria_pueblo_ormerod.c","door");
	add_exit("oeste",ROOMORM"pueblo_ormerod_4.c","standard");
	add_exit("sudeste",ROOMORM"camino_ormerod_18.c","road");
	add_exit("norte",ROOMORM"entrada_a_pastos_2.c","standard");
}
inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Calle Principal %^RESET%^.");
	set_long(query_short()+"\n"+CALLEP".\n\n");
	set_night_long(quert_short()+"\n"+CALLEPN".\n\n");
	set_zone("pueblo_ormerod");
	add_exit("noroeste",ROOMORM"cruce_ormerod.c","standard");
	add_exit("oeste",ROOMORM"pueblo_ormerod_3.c","standard");
	add_exit("este",ROOMORM"pueblo_ormerod_5.c","standard");
	add_exit("noreste",ROOMORM"entrada_a_pastos_2.c","standard");
	add_exit("sur",ROOMORM"camino_ormerod_13.c","road");
}
inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Calle Principal %^RESET%^.");
	set_long(query_short()+"\n"+CALLEP".\n\n");
	set_night_long(quert_short()+"\n"+CALLEPN".\n\n");
	set_zone("pueblo_ormerod");
	add_exit("sudoeste",ROOMORM"camino_ormerod_9.c","road");
	add_exit("este",ROOMORM"pueblo_ormerod_2.c","standard");
	add_exit("norte",ROOMORM"entrada_a_pastos_1.c","standard");
}
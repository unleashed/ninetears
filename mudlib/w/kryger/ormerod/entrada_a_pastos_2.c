inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup ()
{

	set_short("%^BOLD%^GREEN%^Entrada a pastos de Ormerod%^RESET%^.\n");
	set_long(query_short()+"\n"+ENTRADAP".\n\n");
	set_night_long(query_short()+"\n"+ENTRADAPN".\n\n");
	add_exit("norte",ROOMORM"pasto_ormerod_57.c","gate");
	add_exit("sur",ROOMORM"pueblo_ormerod_5.c","standard");
	add_exit("sudoeste",ROOMORM"pueblo_ormerod_4.c","standard");
	add_exit("este",ROOMORM"camino_ormerod_19.c","road");
}
inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Establos %^WHITE%^o0%^RED%^Bloupt%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_D".\n\n");
	add_exit("noreste",ROOMORM"camino_ormerod_10.c","door");
	add_exit("arriba",ROOMORM"casa_ormerod_d.c","stair");
}
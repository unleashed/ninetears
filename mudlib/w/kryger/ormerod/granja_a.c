inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Granja de cerdos %^WHITE%^o0%^RED%^Martis%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_A".\n\n");
	add_exit("sur",ROOMORM"camino_ormerod_16.c","door");
	add_exit("arriba",ROOMORM"casa_ormerod_a.c","stair");
}
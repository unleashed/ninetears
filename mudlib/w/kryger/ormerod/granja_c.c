inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Granja de ovejas %^WHITE%^o0%^RED%^Rortet%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_C".\n\n");
	add_exit("oeste",ROOMORM"camino_ormerod_29.c","door");
	add_exit("arriba",ROOMORM"casa_ormerod_c.c","stair");
}
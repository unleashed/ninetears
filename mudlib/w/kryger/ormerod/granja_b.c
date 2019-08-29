inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Ganaderia %^WHITE%^o0%^RED%^Fullot%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_B".\n\n");
	add_exit("sudoeste",ROOMORM"camino_ormerod_28.c","door");
	add_exit("arriba",ROOMORM"casa_ormerod_b.c","stair");
}
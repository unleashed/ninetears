//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Establos %^WHITE%^o0%^RED%^Bloupt%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_D".\n\n");
	add_clone(NPC+"bloupt_ormerod.c",1);
	set_exit_color("rojo_o");
	add_exit("noreste",ROOMORMC"camino_ormerod_10.c","standard");
	add_exit("arriba",ROOMORMP"casa_ormerod_d.c","stair");
}
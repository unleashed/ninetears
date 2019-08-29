//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Granja de ovejas %^WHITE%^o0%^RED%^Rortet%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_C".\n\n");
	add_clone(NPC+"rortet_ormerod.c",1);
	set_exit_color("rojo_o");
	add_exit("oeste",ROOMORMC"camino_ormerod_29.c","standard");
	add_exit("arriba",ROOMORMP"casa_ormerod_c.c","stair");
}
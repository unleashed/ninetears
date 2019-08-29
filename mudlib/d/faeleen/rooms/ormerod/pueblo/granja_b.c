//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Ganaderia %^WHITE%^o0%^RED%^Fullot%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_B".\n\n");
	add_clone(NPC+"fullot_ormerod.c",1);
	set_exit_color("rojo_o");
	add_exit("sudoeste",ROOMORMC"camino_ormerod_28.c","standard");
	add_exit("arriba",ROOMORMP"casa_ormerod_b.c","stair");
}
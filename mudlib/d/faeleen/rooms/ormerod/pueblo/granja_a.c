//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Granja de cerdos %^WHITE%^o0%^RED%^Martis%^WHITE%^0o%^RESET%^.\n");
	set_long(query_short()+"\n"+GRANJA_A".\n\n");
	add_clone(NPC+"martis_ormerod.c",1);
	set_exit_color("rojo_o");
	add_exit("sur",ROOMORMC"camino_ormerod_16.c","standard");
	add_exit("arriba",ROOMORMP"casa_ormerod_a.c","stair");
}
//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Casa%^RESET%^.\n");
	set_long(query_short()+"\n"+CASA".\n\n");
	set_exit_color("rojo_o");
	add_exit("abajo",ROOMORMP"granja_d.c","stair");
}
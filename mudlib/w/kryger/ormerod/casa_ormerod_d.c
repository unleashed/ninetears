inherit "/std/room.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Casa%^RESET%^.\n");
	set_long(query_short()+"\n"+CASA".\n\n");
	add_exit("abajo",ROOMORM"granja_d.c","stair");
}
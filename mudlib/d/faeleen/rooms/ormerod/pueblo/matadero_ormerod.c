//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Matadero%^RESET%^.\n");
	set_long(query_short()+"\n"+MATADERO".\n\n");
    set_zone("pueblo_ormerod");
	set_exit_color("amarillo_c");
	add_exit("sudeste",ROOMORMP"cruce_ormerod.c","standard");
}
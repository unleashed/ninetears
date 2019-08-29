//Kryger 2002//
inherit "/std/room.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Esquiladora%^RESET%^.");
	set_long(query_short()+"\n"+ESQUILADORA".\n\n");
	set_exit_color("amarillo_c");
	add_exit("norte",ROOMORMP"pueblo_ormerod_3.c","standar");
}
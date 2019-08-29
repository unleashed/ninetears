//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLACK%^Corral%^RESET%^.\n");
	set_long(query_short()+"\n"+CORRAL".\n\n");
	set_night_long(query_short()+"\n"+CORRALN".\n\n");
	set_zone("corral_ormerod");
	set_exit_color("rojo_c");
	add_exit("norte",ROOMORMCO"corral_ormerod_5.c","standard");
	add_exit("oeste",ROOMORMCO"corral_ormerod_2.c","standard");
	add_exit("noreste",ROOMORMCO"corral_ormerod_9.c","standard");
}
//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^YELLOW%^Camino a la Playa%^RESET%^.");
	set_long(query_short()+"\n"+CAMINOP".\n\n");
	set_night_long(query_short()+"\n"+CAMINOPN".\n\n");
	set_zone("camino_playa_rongrond");
    set_exit_color("verde_c");
	add_exit("noroeste",ROOMRONPY"camino_playa_rongrond_2.c","road");
	add_exit("norte",ROOMRONPY"camino_playa_rongrond_4.c","road");
}
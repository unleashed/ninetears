//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Caminos%^RESET%^.");
	set_long(query_short()+"\n"+CAMINO".\n\n");
	set_night_long(query_short()+"\n"+CAMINON".\n\n");
	set_zone("camino_rongrond");
    set_exit_color("negro");
	add_exit("este",ROOMRONC"camino_rongrond_5.c","road");
	add_exit("norte",ROOMRONC"camino_rongrond_4.c","road");
}
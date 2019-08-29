//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Viñedos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASS2".\n\n");
	set_night_long(query_short()+"\n"+VINYASSN2".\n\n");
	set_zone("viñedo_sur_rongrond");
    set_exit_color("verde_c");
	add_exit("sudeste",ROOMRONVS"viñedo_sur_rongrond_26.c","plain");
	add_exit("oeste",ROOMRONVS"viñedo_sur_rongrond_17.c","plain");
	add_exit("norte",ROOMRONVS"viñedo_sur_rongrond_23.c","plain");
}
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Vinyedos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASS2".\n\n");
	set_night_long(query_short()+"\n"+VINYASSN2".\n\n");
	set_zone("vinyedo_norte_rongrond");
    set_exit_color("verde_c");
	add_exit("este",ROOMRONVS"vinyedo_sur_rongrond_13.c","plain");
	add_exit("norte",ROOMRONVS"vinyedo_sur_rongrond_9.c","plain");
	add_exit("noroeste",ROOMRONVS"vinyedo_sur_rongrond_4.c","plain");
	add_exit("sur",ROOMRONVS"vinyedo_sur_rongrond_7.c","plain");
}
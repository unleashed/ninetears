inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Vinyedos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASS1".\n\n");
	set_night_long(query_short()+"\n"+VINYASSN1".\n\n");
	set_zone("vinyedo_norte_rongrond");
    set_exit_color("verde_c");
	add_exit("oeste",ROOMRONVS"vinyedo_sur_rongrond_6.c","plain");
	add_exit("este",ROOMRONVS"vinyedo_sur_rongrond_16.c","plain");
}
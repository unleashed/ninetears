inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^GREEN%^Vinyedos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASN2".\n\n");
	set_night_long(query_short()+"\n"+VINYASNN2".\n\n");
	set_zone("vinyedo_norte_rongrond");
    set_exit_color("verde_o");
	add_exit("sudeste",ROOMRONVN"vinyedo_norte_rongrond_5.c","plain");
	add_exit("noroeste",ROOMRONVN"vinyedo_norte_rongrond_1.c","plain");
}
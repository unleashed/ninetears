inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^GREEN%^Vinyedos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASN1".\n\n");
	set_night_long(query_short()+"\n"+VINYASNN1".\n\n");
	set_zone("vinyedo_norte_rongrond");
    set_exit_color("verde_o");
	add_exit("sudeste",ROOMRONVN"vinyedo_norte_rongrond_19.c","plain");
	add_exit("sudoeste",ROOMRONVN"vinyedo_norte_rongrond_8.c","plain");
	add_exit("sur",ROOMRONVN"vinyedo_norte_rongrond_12.c","plain");
}
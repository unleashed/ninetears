//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^GREEN%^Vi�edos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n"+VINYASS2".\n\n");
	set_night_long(query_short()+"\n"+VINYASSN2".\n\n");
	set_zone("vi�edo_sur_rongrond");
    set_exit_color("verde_c");
	add_exit("noroeste",ROOMRONVS"vi�edo_sur_rongrond_22.c","plain");
	add_exit("oeste",ROOMRONVS"vi�edo_sur_rongrond_21.c","plain");
	add_exit("norte",ROOMRONVS"vi�edo_sur_rongrond_27.c","plain");
}
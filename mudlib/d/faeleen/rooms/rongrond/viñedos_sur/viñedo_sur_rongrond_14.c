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
	add_exit("este",ROOMRONVS"vi�edo_sur_rongrond_19.c","plain");
	add_exit("sur",ROOMRONVS"vi�edo_sur_rongrond_13.c","plain");
	add_exit("oeste",ROOMRONVS"vi�edo_sur_rongrond_9.c","plain");
}
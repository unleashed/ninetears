//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^GREEN%^Vi�edos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n\n"+VINYASN2".\n\n");
	set_night_long(query_short()+"\n\n"+VINYASNN2".\n\n");
	set_zone("vi�edo_norte_rongrond");
    set_exit_color("verde_o");
	add_exit("norte",ROOMRONVN"vi�edo_norte_rongrond_15.c","plain");
	add_exit("sudeste",ROOMRONP"pueblo_rongrond_14.c","standard");
}
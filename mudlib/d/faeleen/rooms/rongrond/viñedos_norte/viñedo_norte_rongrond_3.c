//Kryger 2002//
inherit "/std/outside.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^GREEN%^Vi�edos de Rongrond%^RESET%^.");
	set_long(query_short()+"\n\n"+VINYASN1".\n\n");
	set_night_long(query_short()+"\n\n"+VINYASNN1".\n\n");
	set_zone("vi�edo_norte_rongrond");
    set_exit_color("verde_o");
	add_exit("sudeste",ROOMRONVN"vi�edo_norte_rongrond_6.c","plain");
	add_exit("noreste",ROOMRONVN"vi�edo_norte_rongrond_7.c","plain");
	add_exit("norte",ROOMRONVN"vi�edo_norte_rongrond_4.c","plain");
}
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
	add_exit("noreste",ROOMRONVN"vi�edo_norte_rongrond_25.c","plain");
	add_exit("noroeste",ROOMRONVN"vi�edo_norte_rongrond_17.c","plain");
	add_exit("sur",ROOMRONVN"vi�edo_norte_rongrond_20.c","plain");
	add_exit("sudoeste",ROOMRONVN"vi�edo_norte_rongrond_16.c","plain");
}
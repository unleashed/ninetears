//Kryger 2002//
inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Pueblo de Rongrond:Calle %^RED%^Seithell%^RESET%^");
	set_long(query_short()+"\n\n"+PUEBLO2".\n\n");
	set_night_long(query_short()+"\n\n"+PUEBLON2".\n\n");
	set_zone("pueblo_rongrond");
	add_clone(NPC+"npcs_rongrond.c",3);
    set_exit_color("amarillo_c");
	add_exit("noroeste",ROOMRONP"pueblo_rongrond_11.c","standard");
	add_exit("sudeste",ROOMRONP"pueblo_rongrond_15.c","standard");
	add_exit("sur",ROOMRONP"pueblo_rongrond_12.c","standard");
}
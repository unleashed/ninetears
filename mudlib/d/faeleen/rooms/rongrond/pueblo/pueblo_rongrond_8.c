//Kryger 2002//
inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^RED%^Pueblo de Rongrond:Calle %^RED%^Reirid%^RESET%^");
	set_long(query_short()+"\n\n"+PUEBLO1".\n\n");
	set_night_long(query_short()+"\n\n"+PUEBLON1".\n\n");
	set_zone("pueblo_rongrond");
	add_clone(NPC+"npcs_rongrond.c",3);
    set_exit_color("amarillo_c");
	add_exit("oeste",ROOMRONP"pueblo_rongrond_5.c","standard");
	add_exit("este",ROOMRONP"pueblo_rongrond_11.c","standard");
}
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
	add_exit("norte",ROOMRONP"pueblo_rongrond_18.c","standard");
	add_exit("sudoeste",ROOMRONP"pueblo_rongrond_15.c","standard");
	add_exit("este",ROOMRONC"camino_rongrond_1.c","gate");
}
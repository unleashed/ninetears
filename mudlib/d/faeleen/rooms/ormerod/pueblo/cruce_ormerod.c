//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup()
{
	set_short("%^BOLD%^BLUE%^Cruce%^RESET%^.");
	set_long(query_short()+"\n"+CRUCE".\n\n");
	set_night_long(query_short()+"\n"+CRUCEN".\n\n");
	set_zone("pueblo_ormerod");
	day_clone(NPC"npcs_rongrond.c",2);
	set_exit_color("amarillo_c");
	add_exit("noroeste",ROOMORMP"matadero_ormerod.c","standard");
	add_exit("sudoeste",ROOMORMP"pueblo_ormerod_2.c","standard");
	add_exit("sudeste",ROOMORMP"pueblo_ormerod_4.c","standard");
	add_exit("taberna",ROOMORMP"taberna_ormerod.c","standard");
	add_exit("herreria",ROOMORMP"herreria_ormerod.c","standard");
	add_exit("noreste",ROOMORMC"camino_ormerod_14.c","standard");
}
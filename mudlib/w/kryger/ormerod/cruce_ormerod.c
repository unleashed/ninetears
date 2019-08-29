inherit "/std/ciudad.c";
#include "../../path.h"
#include "path.h

void setup()
{
	set_short("%^BOLD%^BLUE%^Cruce%^RESET%^.");
	set_long(query_short()+"\n"+CRUCE".\n\n");
	set_night_long(query_short()+"\n"+CRUCEN".\n\n");
	set_zone("pueblo_ormerod");
	add_exit("noroeste",ROOMORM"matadero_ormerod.c","standard");
	add_exit("sudoeste",ROOMORM"pueblo_ormerod_2.c","standard");
	add_exit("sudeste",ROOMORM"pueblo_ormerod_4.c","standard");
	add_exit("taberna",ROOMORM"taberna_ormerod.c","standard");
	add_exit("herreria",ROOMORM"herreria_ormerod.c","standard");
	add_exit("noreste",ROOMORM"camino_ormerod_14.c","standard");
}
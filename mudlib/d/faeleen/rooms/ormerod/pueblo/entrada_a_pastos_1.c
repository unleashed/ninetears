//Kryger 2002//
inherit "/std/outside.c";
#include "../../../path.h"
#include "path.h"

void setup ()
{

	set_short("%^BOLD%^GREEN%^Entrada a pastos de Ormerod%^RESET%^.\n");
	set_long(query_short()+"\n"+ENTRADAP".\n\n");
	set_night_long(query_short()+"\n"+ENTRADAPN".\n\n");
add_sign("Ves un cartel con las reglas de los pastos de ormerod ","\n                         PASTOS DE ORMEROD                                     ""\n                         -----------------                                     ""\n\n         -Entrada a los pastos, por favor no atacar a los animales           ""\n           esta penado.                                                        ""\n           -Todo aquel que ataque a los animales sera perseguido por           ""\n           los vaqueros.                                                       ""\n                                                                               ","cartel","cartel");
	set_exit_color("verde_o");
	add_exit("norte",ROOMORMPO"pasto_ormerod_36.c","gate");
	add_exit("sur",ROOMORMP"pueblo_ormerod_1.c","standard");
	add_exit("sudeste",ROOMORMP"pueblo_ormerod_2.c","standard");
}
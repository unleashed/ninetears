//Kryger 2003//
inherit "/std/outside.c";
#include "../path.h"

void setup()
{

	set_short("%^BOLD%^BLACK%^Campo %^RESET%^de la %^RED%^Discordia%^RESET%^.\n");
	set_long(query_short()+"\n   Te encuentras en un campo lleno de Huesos. Este campo "
"ha sido tristemente el escenario de miles de batallas entre las fuerzas del Mal y el Bien, "
"y aun en estos tiempos no cesan las batallas, nunca habra paz en el Campo de la Discordia, "
"nadie sabe exactamente donde se encuentra, es un campo rodeado de portales dimensionales "
"que dan acceso al mundo de driade, juraria que es una dimension alternativa, pero nadie "
"puede dar fe de ello.\n\n");
	set_zone("campo_discordia");
	set_exit_color("amarillo_c");
	add_exit("noreste",ROOMRING"campo_discordia_24.c","standard");
	add_exit("noroeste",ROOMRING"campo_discordia_12.c","standard");
	add_exit("sur",ROOMRING"campo_discordia_16.c","standard");
}
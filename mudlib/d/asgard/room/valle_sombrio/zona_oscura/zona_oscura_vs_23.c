//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("sur",ROOMVSZB"zona_basta_vs_1.c","standard");
	add_exit("oeste",ROOMVSZO"zona_oscura_vs_19.c","standard");
	add_exit("noreste",ROOMVSZO"zona_oscura_vs_29.c","standard");
}
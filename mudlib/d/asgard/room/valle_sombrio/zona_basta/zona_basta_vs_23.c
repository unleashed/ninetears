//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("sudeste",ROOMVSZB"zona_basta_vs_24.c","standard");
	add_exit("oeste",ROOMVSZB"zona_basta_vs_22.c","standard");
}
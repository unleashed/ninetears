//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("oeste",ROOMVSZB"zona_basta_vs_26.c","standard");
	add_exit("sudeste",ROOMVSZD"zona_densa_vs_11.c","standard");
}
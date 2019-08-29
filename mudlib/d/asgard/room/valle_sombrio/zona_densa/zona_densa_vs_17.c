//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("sur",ROOMVSZD"zona_densa_vs_16.c","standard");
	add_exit("sudeste",ROOMVSZD"zona_densa_vs_21.c","standard");
}
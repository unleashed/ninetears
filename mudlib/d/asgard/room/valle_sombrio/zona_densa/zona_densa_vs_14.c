//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("oeste",ROOMVSZD"zona_densa_vs_9.c","standard");
	add_exit("norte",ROOMVSZD"zona_densa_vs_15.c","standard");
	add_exit("sudeste",ROOMVSZD"zona_densa_vs_19.c","standard");
}
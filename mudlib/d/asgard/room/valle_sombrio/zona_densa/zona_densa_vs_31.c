//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("noroeste",ROOMVSZD"zona_densa_vs_27.c","standard");
	add_exit("sur",ROOMVSZD"zona_densa_vs_30.c","standard");
	add_exit("sudeste",ROOMVSZD"zona_densa_vs_34.c","standard");
}
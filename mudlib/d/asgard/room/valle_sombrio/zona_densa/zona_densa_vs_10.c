//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("noroeste",ROOMVSZD"zona_densa_vs_6.c","standard");
	add_exit("este",ROOMVSZD"zona_densa_vs_16.c","standard");
}
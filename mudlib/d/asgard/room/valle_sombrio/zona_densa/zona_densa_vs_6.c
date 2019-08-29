//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("sudoeste",ROOMVSZD"zona_densa_vs_4.c","standard");
	add_exit("sudeste",ROOMVSZD"zona_densa_vs_10.c","standard");
}
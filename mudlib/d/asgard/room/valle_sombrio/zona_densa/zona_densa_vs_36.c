//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("sudoeste",ROOMVSZD"zona_densa_vs_34.c","standard");
	add_exit("norte",ROOMVSZD"zona_densa_vs_37.c","standard");
}
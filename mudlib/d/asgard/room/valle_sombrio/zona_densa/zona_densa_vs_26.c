//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("sudoeste",ROOMVSZD"zona_densa_vs_23.c","standard");
	add_exit("noreste",ROOMVSZD"zona_densa_vs_29.c","standard");
}
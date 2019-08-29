//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("noreste",ROOMVSZD"zona_densa_vs_26.c","standard");
	add_exit("oeste",ROOMVSZD"zona_densa_vs_18.c","standard");
	add_exit("sur",ROOMVSZD"zona_densa_vs_22.c","standard");
}
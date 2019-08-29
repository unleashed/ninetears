//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("oeste",ROOMVSZD"zona_densa_vs_21.c","standard");
	add_exit("este",ROOMVSZD"zona_densa_vs_28.c","standard");
}
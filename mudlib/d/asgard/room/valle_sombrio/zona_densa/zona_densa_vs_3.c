//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(5);
	add_exit("sudoeste",ROOMVSZD"zona_densa_vs_2.c","standard");
	add_exit("este",ROOMVSZD"zona_densa_vs_5.c","standard");
	add_exit("oeste",ROOMVSZC"zona_clara_vs_51.c","standard");
}
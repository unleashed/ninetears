//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("sudeste",ROOMVSZC"zona_clara_vs_14.c","standard");
	add_exit("norte",ROOMVSZC"zona_clara_vs_8.c","standard");
	add_exit("sudoeste",ROOMVSZB"zona_basta_vs_9.c","standard");
}
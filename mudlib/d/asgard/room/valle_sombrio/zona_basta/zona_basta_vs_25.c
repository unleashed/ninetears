//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("norte",ROOMVSZB"zona_basta_vs_26.c","standard");
	add_exit("sudoeste",ROOMVSZB"zona_basta_vs_24.c","standard");
}
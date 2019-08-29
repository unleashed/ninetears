//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("sudeste",ROOMVSZB"zona_basta_vs_11.c","standard");
	add_exit("noroeste",ROOMVSZB"zona_basta_vs_7.c","standard");
	add_exit("sudoeste",ROOMVSZB"zona_basta_vs_6.c","standard");
}
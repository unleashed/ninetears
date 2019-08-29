//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("noreste",ROOMVSZB"zona_basta_vs_4.c","standard");
	add_exit("noroeste",ROOMVSZB"zona_basta_vs_2.c","standard");
}
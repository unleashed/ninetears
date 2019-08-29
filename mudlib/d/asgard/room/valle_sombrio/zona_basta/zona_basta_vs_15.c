//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("este",ROOMVSZB"zona_basta_vs_16.c","standard");
	add_exit("oeste",ROOMVSZB"zona_basta_vs_14.c","standard");
	add_exit("noreste",ROOMVSZB"zona_basta_vs_17.c","standard");
}
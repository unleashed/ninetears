//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("este",ROOMVSZB"zona_basta_vs_18.c","standard");
	add_exit("sudoeste",ROOMVSZB"zona_basta_vs_15.c","standard");
	add_exit("sur",ROOMVSZB"zona_basta_vs_16.c","standard");
}
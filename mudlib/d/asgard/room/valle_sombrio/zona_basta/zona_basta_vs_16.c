//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("norte",ROOMVSZB"zona_basta_vs_17.c","standard");
	add_exit("oeste",ROOMVSZB"zona_basta_vs_15.c","standard");
	add_exit("sur",ROOMVSAT"alrededores_templo_vs_23.c","standard");
}
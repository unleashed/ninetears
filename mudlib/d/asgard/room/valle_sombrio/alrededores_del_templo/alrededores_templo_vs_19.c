//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("oeste",ROOMVSAT"alrededores_templo_vs_16.c","standard");
	add_exit("sudoeste",ROOMVSAT"alrededores_templo_vs_15.c","standard");
	add_exit("norte",ROOMVSZB"zona_basta_vs_11.c","standard");
}
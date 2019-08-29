//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("sudeste",ROOMVSAT"alrededores_templo_vs_27.c","standard");
	add_exit("norte",ROOMVSZB"zona_basta_vs_16.c.c","standard");
}
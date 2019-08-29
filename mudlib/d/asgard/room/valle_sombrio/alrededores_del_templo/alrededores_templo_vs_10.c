//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("oeste",ROOMVSAT"alrededores_templo_vs_3.c","standard");
	add_exit("sudeste",ROOMVSAT"alrededores_templo_vs_14.c","standard");
}
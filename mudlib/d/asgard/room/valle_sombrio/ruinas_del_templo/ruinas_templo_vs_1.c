//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(1);
	add_exit("oeste",ROOMVSAT"alrededores_templo_vs_11.c","standard");
	add_exit("sudeste",ROOMVSRT"ruinas_templo_vs_3.c","standard");
}
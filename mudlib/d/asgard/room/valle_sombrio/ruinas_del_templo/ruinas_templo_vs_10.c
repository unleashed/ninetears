//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(1);
	add_exit("sudeste",ROOMVSAT"alrededores_templo_vs_30.c","standard");
	add_exit("sur",ROOMVSRT"ruinas_templo_vs_9.c","standard");
}
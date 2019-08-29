//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("sur",ROOMVSAT"alrededores_templo_vs_17.c","standard");
	add_exit("norte",ROOMVSRT"ruinas_templo_vs_2.c","standard");
}
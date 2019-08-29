//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("sur",ROOMVSAT"alrededores_templo_vs_31.c","standard");
	add_exit("oeste",ROOMVSAT"alrededores_templo_vs_25.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(1);
	add_exit("sur",ROOMVSAT"alrededores_templo_vs_18.c","standard");
	add_exit("este",ROOMVSRT"ruinas_templo_vs_4.c","standard");
}
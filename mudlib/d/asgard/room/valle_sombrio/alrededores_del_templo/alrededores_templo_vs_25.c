//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("norte",ROOMVSAT"alrededores_templo_vs_26.c","standard");
	add_exit("este",ROOMVSAT"alrededores_templo_vs_32.c","standard");
}
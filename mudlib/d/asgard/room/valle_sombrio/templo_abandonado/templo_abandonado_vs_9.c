//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("noroeste",ROOMVSTA"templo_abandonado_vs_6.c","standard");
	add_exit("sur",ROOMVSTA"templo_abandonado_vs_8.c","standard");
}
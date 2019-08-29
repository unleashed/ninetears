//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("noreste",ROOMVSTA"templo_abandonado_vs_10.c","standard");
	add_exit("noroeste",ROOMVSTA"templo_abandonado_vs_3.c","standard");
	add_exit("sudeste",ROOMVSTA"templo_abandonado_vs_9.c","standard");
	add_exit("sudoeste",ROOMVSTA"templo_abandonado_vs_2.c","standard");
}
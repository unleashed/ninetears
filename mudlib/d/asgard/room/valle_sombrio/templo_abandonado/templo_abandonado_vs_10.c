//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("sudoeste",ROOMVSTA"templo_abandonado_vs_6.c","standard");
	add_exit("norte",ROOMVSTA"templo_abandonado_vs_11.c","standard");
}
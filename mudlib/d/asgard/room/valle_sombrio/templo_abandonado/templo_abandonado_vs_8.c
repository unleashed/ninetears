//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("norte",ROOMVSTA"templo_abandonado_vs_9.c","standard");
	add_exit("oeste",ROOMVSTA"templo_abandonado_vs_5.c","standard");
	add_exit("sudoeste",ROOMVSRT"ruinas_templo_vs_5.c","standard");
}
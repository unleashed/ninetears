//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("norte",ROOMVSTA"templo_abandonado_vs_2.c","standard");
	add_exit("este",ROOMVSTA"templo_abandonado_vs_5.c","standard");
}
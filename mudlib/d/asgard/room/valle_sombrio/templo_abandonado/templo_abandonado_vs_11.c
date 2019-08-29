//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);
	add_exit("oeste",ROOMVSTA"templo_abandonado_vs_7.c","standard");
	add_exit("sur",ROOMVSTA"templo_abandonado_vs_10.c","standard");
}
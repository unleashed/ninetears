//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("sur",ROOMVSTA"templo_abandonado_vs_7.c","standard");
	add_exit("norte",ROOMVSZB"zona_basta_vs_14.c","standard");
}
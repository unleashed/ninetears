//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(2);

	add_exit("este",ROOMVSTA"templo_abandonado_vs_11.c","standard");
	add_exit("oeste",ROOMVSTA"templo_abandonado_vs_4.c","standard");
	add_exit("norte",ROOMVSZB"zona_basta_vs_13.c","standard");
}
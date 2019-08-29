//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);

	add_exit("norte",ROOMVSZO"zona_oscura_vs_23.c","standard");
	add_exit("este",ROOMVSZB"zona_basta_vs_2.c","standard");
}
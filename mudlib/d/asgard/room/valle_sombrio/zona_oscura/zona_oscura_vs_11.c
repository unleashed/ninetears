//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("oeste",ROOMVSZO"zona_oscura_vs_7.c","standard");
	add_exit("norte",ROOMVSZO"zona_oscura_vs_12.c","standard");
}
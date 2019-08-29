//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("oeste",ROOMVSZO"zona_oscura_vs_16.c","standard");
	add_exit("este",ROOMVSZO"zona_oscura_vs_26.c","standard");
	add_exit("sudeste",ROOMVSZO"zona_oscura_vs_25.c","standard");
}
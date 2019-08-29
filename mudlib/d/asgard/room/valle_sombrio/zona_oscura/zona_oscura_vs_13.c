//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("norte",ROOMVSZO"zona_oscura_vs_14.c","standard");
	add_exit("sur",ROOMVSZO"zona_oscura_vs_12.c","standard");
	}
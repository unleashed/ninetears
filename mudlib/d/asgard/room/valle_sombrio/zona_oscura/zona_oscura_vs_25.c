//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("noroeste",ROOMVSZO"zona_oscura_vs_21.c","standard");
	add_exit("sudoeste",ROOMVSZO"zona_oscura_vs_20.c","standard");
}

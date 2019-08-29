//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("noroeste",ROOMVSZO"zona_oscura_vs_32.c","standard");
	add_exit("sudoeste",ROOMVSZO"zona_oscura_vs_31.c","standard");
	add_exit("norte",ROOMVSZO"zona_oscura_vs_37.c","standard");
}
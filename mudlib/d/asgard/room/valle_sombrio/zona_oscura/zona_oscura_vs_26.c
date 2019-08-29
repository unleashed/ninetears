//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(6);
	add_exit("oeste",ROOMVSZO"zona_oscura_vs_21.c","standard");
	add_exit("noreste",ROOMVSZO"zona_oscura_vs_32.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(1);
	add_exit("oeste",ROOMVSRT"ruinas_templo_vs_2.c","standard");
	add_exit("noreste",ROOMVSRT"ruinas_templo_vs_5.c","standard");
}
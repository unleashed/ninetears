//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(1);
	add_exit("sudoeste",ROOMVSRT"ruinas_templo_vs_6.c","standard");
	add_exit("norte",ROOMVSRT"ruinas_templo_vs_8.c","standard");
}
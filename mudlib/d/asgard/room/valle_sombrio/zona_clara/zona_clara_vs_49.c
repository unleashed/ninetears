//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("oeste",ROOMVSZC"zona_clara_vs_44.c","standard");
	add_exit("sudeste",ROOMVSZC"zona_clara_vs_51.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("este",ROOMVSZC"zona_clara_vs_19.c","standard");
	add_exit("noroeste",ROOMVSZC"zona_clara_vs_7.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("sur",ROOMVSZC"zona_clara_vs_8.c","standard");
	add_exit("norte",ROOMVSZC"zona_clara_vs_10.c","standard");
}
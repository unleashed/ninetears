//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("este",ROOMVSZC"zona_clara_vs_5.c","standard");
	add_exit("sur",ROOMVSZC"zona_clara_vs_1.c","standard");
	add_exit("oeste",ROOMVSZO"zona_oscura_vs_39.c","standard");
}
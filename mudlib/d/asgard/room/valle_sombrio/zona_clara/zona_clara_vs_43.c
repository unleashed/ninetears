//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("oeste",ROOMVSZC"zona_clara_vs_38.c","standard");
	add_exit("sur",ROOMVSZC"zona_clara_vs_42.c","standard");
	add_exit("este",ROOMVSZC"zona_clara_vs_48.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("este",ROOMVSZC"zona_clara_vs_45.c","standard");
	add_exit("noreste",ROOMVSZC"zona_clara_vs_46.c","standard");
}
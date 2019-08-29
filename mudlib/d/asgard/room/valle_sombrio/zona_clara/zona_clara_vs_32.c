//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("sudoeste",ROOMVSZC"zona_clara_vs_27.c","standard");
	add_exit("noroeste",ROOMVSZC"zona_clara_vs_28.c","standard");
}
//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(4);
	add_exit("sudoeste",ROOMVSZC"zona_clara_vs_5.c","standard");
	add_exit("oeste",ROOMVSZC"zona_clara_vs_6.c","standard");
	add_exit("este",ROOMVSZC"zona_clara_vs_17.c","standard");
	add_exit("norte",ROOMVSZC"zona_clara_vs_13.c","standard");
}
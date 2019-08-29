//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("sur",ROOMVSZB"zona_basta_vs_8.c","standard");
	add_exit("noreste",ROOMVSZC"zona_clara_vs_7.c","standard");
}
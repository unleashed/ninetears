//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(3);
	add_exit("este",ROOMVSZB"zona_basta_vs_12.c","standard");
	add_exit("noroeste",ROOMVSZB"zona_basta_vs_10.c","standard");
	add_exit("sur",ROOMVSAT"alrededores_templo_vs_19.c","standard");
}
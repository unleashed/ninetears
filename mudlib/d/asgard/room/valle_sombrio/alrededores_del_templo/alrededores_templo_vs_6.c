//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("sudoeste",ROOMVSAT"alrededores_templo_vs_2.c","standard");
	add_exit("noreste",ROOMVSAT"alrededores_templo_vs_11.c","standard");
}
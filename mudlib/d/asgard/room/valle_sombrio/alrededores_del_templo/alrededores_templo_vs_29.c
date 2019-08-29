//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("norte",ROOMVSAT"alrededores_templo_vs_30.c","standard");
	add_exit("sudoeste",ROOMVSAT"alrededores_templo_vs_24.c","standard");
	add_exit("noreste",ROOMVSAT"alrededores_templo_vs_35.c","standard");
}
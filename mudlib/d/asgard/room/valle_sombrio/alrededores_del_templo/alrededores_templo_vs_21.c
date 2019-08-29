//Kryger 2003//
inherit "/d/asgard/handlers/base_handler_valle_2.c";
#include "../path.h"
void setup()
{

	habitacion(0);
	add_exit("noroeste",ROOMVSAT"alrededores_templo_vs_20.c","standard");
	add_exit("kryger","/w/kryger/workroom.c","standard");
}
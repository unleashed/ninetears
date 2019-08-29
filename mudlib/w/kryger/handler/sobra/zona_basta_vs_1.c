//Kryger 2003//
inherit "/d/asgard/handlers/base_valle_handler.c";
#include "../path.h"
#include "path.h"
void setup()
{

	habitacion(0);

	set_exit_color("verde_o");
	add_exit("norte",ROOMVSZO"zona_oscura_vs_23.c","standard");
	add_exit("este",ROOMVSZB"zona_basta_vs_2.c","standard");
}
//Huascar

#include "../path.h"
inherit "/std/outside.c";
void setup()
{
set_short("%^RED%^Camino entre la niebla%^RESET%^");
set_long("%^GREEN%^Camino entre la niebla%^RESET%^\n\nAnte ti se encuentra un terreno verdaderamente desconcertante. "
         "La tierra bajo tus pies esta fuertemente compactada por lo que deduces que se "
	 "trata de un camino transitado pero la niebla reinante es tan densa que te impide "
 	 "ver mas alla de un metro. Por esta causa no pareces ver salida alguna pero "
	 "si de alguna manera llegaste aqui tambien deberias poder salir..\n");
		
    set_light(50);
set_zone("cienaga");
add_clone(NPC"errante.c",random(3)-1);
add_exit("noreste",MAR"M0716.c","hidden");
add_exit("sur",MAR"M0515.c","hidden");
}
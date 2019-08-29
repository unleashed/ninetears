/* By Shimmer */

#include "../path.h"

inherit "/std/room";

void setup() {
   set_zone("rio");
   set_light(50);
   set_short("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Cruce Oeste");
   set_long("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Cruce Oeste\n\n"
   "Te encuentras en un cruce al lado del Rio Rojo, aqui en camino se divide, al norte continua bordeando "
   "el rio hicia las zonas profundas de la cienaga, al noroeste, a los lejos puedes puedes ver la muralla "
   "serpenteando y al sur mas rio hacia la salida del Reino.\n\n");

add_clone(NPCS+"varios_rio.c",1);

add_exit("norte",HAGN+"rio40.c","standard");
add_exit("noroeste",HAGN+"sen3.c","standard");
add_exit("sur",HAGN+"rio42.c","standard");
add_exit("este",HAGN+"cie42.c","standard");

}
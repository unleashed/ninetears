/* By Shimmer */

#include "../path.h"

inherit "/std/room";

void setup() {
   set_zone("rio");
   set_light(50);
   set_short("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Cruce Este");
   set_long("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Cruce Este\n\n"
   "Te encuentras en un cruce al lado del Rio Rojo, aqui en camino se divide, al norte continua bordeando "
   "el rio hicia las zonas profundas de la cienaga, al noreste, a los lejos puedes puedes ver la muralla "
   "serpenteando y al sur mas rio hacia la salida del Reino.\n\n");

add_clone(NPCS+"varios_rio.c",1);
add_clone(NPCS+"nomada.c",1);

add_exit("norte",HAGN+"rio15.c","standard");
add_exit("noreste",HAGN+"sen4.c","standard");
add_exit("sur",HAGN+"rio13.c","standard");
add_exit("oeste",HAGN+"cie23.c","standard");
}
/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {
   set_exit_color("red");
   set_zone("rio");
   set_light(50);
   set_short("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Zona Sur");
   set_long("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Zona Sur\n\n"
   "Todo esta encharcado a tu alrededor, el color del agua no es normal, un rojo brillante que lo inunda todo "
   "unos metros mas alla puedes ver como el rio discurre paralelo al camino, bordeando la cienaga que se abre "
   "ante ti abarcando el horizonte hasta donde la bruma te deja ver. Lo unico que puedes oir es el chapoteo "
   "de tus botas a medida que caminas y los zumbidos de los mosquitos y el  croar de algun que otro anfibio "
   "que puedes divisar, todo esta demasiado tranquilo.\n\n");

add_clone(NPCS+"varios_rio.c",3);

add_exit("este",HAGN+"rio2.c","standard");
add_exit("oeste",HAGN+"mur73.c","standard");
add_exit("norte",HAGN+"cie5.c","standard");

}
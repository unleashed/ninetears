/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {
   set_exit_color("red");
   set_zone("rio");
   set_light(50);
   set_short("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Zona Este");
   set_long("Camino paralelo al %^BOLD%^%^RED%^Rio Rojo%^RESET%^ : Zona Este\n\n"
   "Aqui el camino y el rio toman hacia el norte, bordeando la cienaga, cada vez se hace "
   "todo mas oscuro y la bruma lo cubre todo, apenas puedes ver poco mas alla de tus narices. "
   "Unos metros mas alla puedes ver como el rio discurre paralelo al camino, bordeando la cienaga que se abre "
   "ante ti abarcando el horizonte hasta donde la bruma te deja ver. Lo unico que puedes oir es el chapoteo "
   "de tus botas a medida que caminas y los zumbidos de los mosquitos y el  croar de algun que otro anfibio "
   "que puedes divisar, todo esta demasiado tranquilo.\n\n");

add_clone(NPCS+"varios_rio.c",random(3));

add_exit("norte",HAGN+"rio17.c","standard");
add_exit("sur",HAGN+"rio15.c","standard");

}
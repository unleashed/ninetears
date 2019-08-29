/* By Shimmer */

#include "../path.h"


inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_light(50);
   set_zone("camino_bosque_harak");
   set_short("Camino entre los arboles%^RESET%^");
   set_long("Camino entre los arboles%^RESET%^\n\n"
   "Te estas acercando al bosque y ya notas como el aire se hace mas y mas puro a tu "
   "alrededor, al norte quedan ya lejos las cienagas y su olor putrefacto y aqui tu "
   "cuerpo se siente mas libre al respirar este aire tan puro.\n\n");


add_clone(NPCS+"varios_humanos.c",random(1));

add_exit("norte",BOSQUEHARAK+"camino6.c","standard");
add_exit("este",BOSQUEHARAK+"camino4.c","standard");
}
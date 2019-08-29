/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_light(50);
   set_zone("camino_bosque_harak");
   set_short("Camino entre los arboles%^RESET%^");
   set_long("Camino entre los arboles%^RESET%^\n\n"
   "Al oeste, ante ti se elevan ya las copas de los grandes arboles del bosque, puedes "
   "ver bandadas de pajaros volando de un lado para otro y oir los grunyidos de los animalillos "
   "cuando pasas cerca de algun matorral, como asustados por tu presencia.\n\n");

add_clone(NPCS+"varios_humanos.c",random(1));

add_exit("oeste",BOSQUEHARAK+"camino7.c","standard");
add_exit("sur",BOSQUEHARAK+"camino5.c","standard");
}
/* By Shimmer */

#include "../path.h"



inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_light(50);
   set_zone("camino_bosque_harak");
   set_short("Camino entre los arboles%^RESET%^");
   set_long("Camino entre los arboles%^RESET%^\n\n"
   "Estas en un camino de tierra, a tu alrededor cada vez hay mas arboles y el aire es mas puro, "
   "si miras alrededor puedes ver como si los arboles estubiesen espiando cada movimiento que das, "
   "sus ramas se mecen acompasadas al ritmo que marca el viento.\n\n");

add_clone(NPCS+"varios_humanos.c",random(1));

add_exit("oeste",BOSQUEHARAK+"camino5.c","standard");
add_exit("noreste",BOSQUEHARAK+"camino3.c","standard");
}
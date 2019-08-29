/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("green");
   set_light(50);
   set_zone("camino_bosque_harak");
   set_short("Camino entre los arboles%^RESET%^");
   set_long("Camino entre los arboles%^RESET%^\n\n"
   "Ante ti se abre ya el frondoso bosque, el camino aqui se pierde ya entre los arboles, "
   "altos y cargados de ramas con miles de hojas todas verdes como si el tiempo y las "
   "estaciones no pasaran por el.\n\n");

add_clone(NPCS+"varios_humanos.c",random(1));

add_exit("noroeste",BOSQUEHARAK+"bos1.c","standard");
add_exit("este",BOSQUEHARAK+"camino6.c","standard");
}
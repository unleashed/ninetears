/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("zhyrkh");
   set_light(50);
   set_short("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "El camino se estrecha ahora formando una especie de pasillo que desemboca en la puerta de "
   "la ciudad, a los lados del camino puedes ver pequenyos ninyos orcos jugando y guardias "
   "vigilando la entrada de la ciudad, la muralla se abre ya cerca y puedes ver ya las puertas "
   "de la ciudad al fondo..\n\n");

add_clone(NPCS+"varios_cerca_zhyrkh.c",random(3));

 
add_exit("oeste",CAMSUR+"cam78.c","standard");
add_exit("sudeste",CAMSUR+"cam76.c","standard");

}
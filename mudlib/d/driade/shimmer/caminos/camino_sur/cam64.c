/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Estas ahora en el centro de un gran valle, los arboles rodean el camino que se pierde en "
   "el horizonte en lo alto de una nueva y baja colina, tras ella esta la ciudad de Zhyrkh, "
   "aunque ahora mismo no la puedes divisar por culpa de la colina que la oculta.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));

add_exit("este",CAMSUR+"cam63.c","standard");
add_exit("oeste",CAMSUR+"cam65.c","standard");

}
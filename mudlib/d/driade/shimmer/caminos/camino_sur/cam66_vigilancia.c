/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("cyan");
   set_zone("zhyrkh");
   set_light(50);
   set_short("%^BOLD%^%^BLACK%^Puesto de Vigilancia%^RESET%^");
   set_long("%^BOLD%^%^BLACK%^Puesto de Vigilancia%^RESET%^\n\n"
   "Este es el puesto de vigilancia orca del camino sur, te encuentras ya cerca de la ciudad de "
   "Zhyrkh, y esta es una especie de avanzadilla, encargada de vigilar el camino y la entrada "
   "a las cercanias de la ciudad.\n\n");

add_clone(NPCS+"guardias_orcos.c",2);

add_exit("este",CAMSUR+"cam65.c","standard");
add_exit("oeste",CAMSUR+"cam67.c","standard");
add_exit("norte",CAMSUR+"cuartel1.c","standard");
add_exit("sur",CAMSUR+"torre1.c","standard");

}
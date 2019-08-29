/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("zhyrkh");
   set_light(50);
   set_short("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Estas en el camino sur, cerca de la ciudad de Zhyrkh, el camino es amplio y totalmente "
   "empedrado, a los lados crecen arbusos bajos y secos, aqui al lado de la ciudad todo parece "
   "arrasado y quemado, es una tierra medio arida que choca con los valles verdes y arbolados "
   "cercanos a la ciudad.\n\n");

add_clone(NPCS+"varios_cerca_zhyrkh.c",random(3));
add_clone("/d/driade/shimmer/npcs/guardias_orcos.c",random(1));
 
add_exit("noroeste",CAMSUR+"cam75.c","standard");
add_exit("sudeste",CAMSUR+"cam73.c","standard");

}
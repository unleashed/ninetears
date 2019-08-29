/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("zhyrkh");
   set_light(50);
   set_short("Cruce del Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Estas en un cruce en el camino sur, al oeste las murallas de Zhyrkh estan ya muy cerca, "
   "al noreste aun puedes divisar el Harak-Din y hacia el norte un estrecho camino empedrado se "
   "abre paso hacia la pequenya montanya cubierta de excavaciones, las Minas de Zhyrkhom.\n\n");

add_clone(NPCS+"varios_cerca_zhyrkh.c",random(3));
add_clone(NPCS+"guardias_orcos.c",random(1));
 
add_exit("sudoeste",CAMSUR+"cam71.c","standard");
add_exit("este",CAMSUR+"cam69.c","standard");
add_exit("norte",ZHYRKHOM+"camino_minas1.c","standard");

}
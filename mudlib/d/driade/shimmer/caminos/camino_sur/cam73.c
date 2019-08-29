/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("zhyrkh");
   set_light(50);
   set_short("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur: Cerca de %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Estas ya cerca de la ciudad orca de Zhyrkh, el olor comienza a ser insoportable, "
   "hacia el oeste puedes ver como las murallas de la ciudad de hacen cada vez mas grandes "
   "a medida que te acercas y al norte ves una pequenya montanya con numerosas excavaciones "
   "en su superficie, las minas.\n\n");

add_clone(NPCS+"varios_cerca_zhyrkh.c",random(3));

 
add_exit("noroeste",CAMSUR+"cam74.c","standard");
add_exit("este",CAMSUR+"cam72.c","standard");

}
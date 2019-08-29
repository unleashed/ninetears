/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "El camino baja ahora por la colina sorteando enormes rocas a ambos lados, la vegetacion comienza "
   "a ser cada vez mas abundante y ya quedan atras las ariscas laderas de la montanya. Puedes ver al  "
   "sudoeste lo que desde la lejania parece una ciudad amurallada.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));


add_exit("noreste",CAMSUR+"cam45.c","standard");
add_exit("sudoeste",CAMSUR+"cam47.c","standard");

}
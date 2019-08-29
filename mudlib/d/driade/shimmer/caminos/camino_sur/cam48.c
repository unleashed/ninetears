/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "En camino transcurre ahora de oeste a este cruzando un gran valle, al final puedes ver ya "
   "con claridad las murallas de Zhyrkh, aun lejanas pero enormes, como resaltando sobre el  "
   "horizonte.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));

add_exit("norte",CAMSUR+"cam47.c","standard");
add_exit("sudoeste",CAMSUR+"cam49.c","standard");

}
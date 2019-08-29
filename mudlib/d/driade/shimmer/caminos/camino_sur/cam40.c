/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "A si echas un vistazo a tu alrededor puedes ver que te encuentras en lo alto de una pequenya "
   "colina, al norte puedes ver aun la cima nevada del Harak-Din, mientras que al sur el terreno "
   "desciende lentamente hasta que se une con el horizonte.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(2));

add_exit("norte",CAMSUR+"cam39.c","standard");
add_exit("sur",CAMSUR+"cam41.c","standard");

}
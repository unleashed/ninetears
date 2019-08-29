/* By Shimmer */

#include "../path.h"

inherit "/std/outside";

void setup() {
  
   set_exit_color("green");
   set_light(50);
   set_zone("camino_bosque_harak");
   set_short("Camino entre los arboles%^RESET%^");
   set_long("Camino entre los arboles%^RESET%^\n\n"
   "Alrededor del camino comienza a haber cada vez mas y mas arboles, y al fondo puedes ver "
   "un gran bosque de altos arboles, si miras al sur puedes ver la majestuosa cumbre nevada "
   "del Harak-Din.\n\n");

add_clone(NPCS+"varios_humanos.c",1);

add_exit("oeste",BOSQUEHARAK+"camino2.c","standard");
add_exit("este",CAMHAGN+"cam18.c","standard");

}
/* By Shimmer */

#include "../../path.h"

inherit "/std/outside";

void setup() {

   set_exit_color("magenta");
   set_zone("caminosur");
   set_light(50);
   set_short("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^");
   set_long("Camino Sur a %^BOLD%^%^RED%^Zhyrkh%^RESET%^\n\n"
   "Delante de ti, a unos metros, puedes ver una especie de puesto de vigilancia orca, una "
   "torre sobresale a la derecha del camino, mientras que a la izquierda una construccion "
   "baja y alargada llama tu atencion.\n\n");

add_clone(NPCS+"varios_camino_sur.c",random(0));

add_exit("este",CAMSUR+"cam64.c","standard");
add_exit("oeste",CAMSUR+"cam66_vigilancia.c","standard");

}
// Aokromes  21/10/1999

inherit "/std/room";
#include "../path.h"

void setup() {

   set_exit_color("white");
   set_light(50);
   set_short("Torre negra");
   set_long("En este punto el camino acaba en un pozo de una oscuridad tal, "
   "que no se ve el fondo, caerse tiene que hacer mucho danyo, seguro que te "
   "matarias si te cayeras al fondo, la mejor alternativa es volver por el "
   "camino por el cual viniste, por el bien de tu integridad fisica.");
add_exit("sur",TN+"tn_20.c","road");

add_item("pozo","Un pozo del cual no se ve el fondo, por lo cual deduces que "
"tiene que estar muyyyyy abajo");

}

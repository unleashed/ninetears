// Aokromes

#include "../path.h"
inherit "/std/room";
void setup() {
   set_light(50);
   set_short("Camino a la Torre Negra");
   set_long("Estas en un tetrico camino, que lentamente asciende "
      "por las colinas de Ostigurth, entre plantas de un color "
      "negruzco, como si estubiesen muertas hace siglos, contaminadas "
    "por el mal que parece contener el ambiente, hacia el sur sube una "
"rampa hacia una fortaleza de aspecto maligno.\n");
add_clone("/d/anduar/torre_negra/obj/viaj.c",1);
   add_exit("noroeste",TN"tn_10","road");
    add_exit("noreste",TN"tn_8","road");
add_exit("arriba",TN1"tn_a_1","road");
}

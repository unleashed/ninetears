/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("yellow");
   set_short("%^BOLD%^Ciudad de Brethem : %^RESET%^GREEN%^Cementerio%^RESET%^");
   long_desc_cementerio();

   crea_npcs_cementerio();

   add_item(({"tumba", "tumbas", "cripta", "criptas", "panteon", "panteones"}), "Numerosas tumbas, criptas y "
              "panteones te rodean por todos lados, la mayoria estan cargados de musgos y insectos dando la "
              "impresion de llevar cientos de anyos ahi inalteradas.\n");
   add_item(({"arbol", "arboles"}), "Entre las tumbas crecen enormes arboles centenarios que apuntan co sus "
              "peladas ramas hacia el cielo, algunos pajaros e insectos pasean por sus ramas.\n");



add_exit("oeste",      BRETHEM + "cemen34.c","standard");
add_exit("este",       BRETHEM + "cemen32.c","standard");


}

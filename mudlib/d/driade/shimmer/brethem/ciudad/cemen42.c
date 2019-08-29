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



add_exit("norte",      BRETHEM + "cemen36.c","standard");
add_exit("sudeste",    BRETHEM + "cemen43.c","standard");


}

void init()
{
   ::init();
   add_action("cloaca", "levanta*r");
   add_action("cloaca", "quita*r");
}

void cloaca(string tapa)
{
   if (!tapa || tapa!="tapa")
   {
      this_player()->notify_fail(query_verb()+" como?\n");
      return 0;
   }
   write("\nTe agachas con cuidado para levantar la tapa metalica que conduce a las cloacas de la ciudad, una vez "
   "abierta te deslizas dentro del agujero tapando denuevo la salida. Ante ti se abren las oscuras y sucias cloacas de Brethem.\n\n");
   say(this_player()->query_cap_name()+" levanta algo con ciudado y se "
   "desliza por un agujero dejandote atonito.\n\n");
   this_player()->move(CLOACASBRE + "clo18.c");
   this_player()->look_me();
   return 1;
}

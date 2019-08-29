/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLACK%^Plaza del Encuentro%^RESET%^");
   set_long("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLACK%^Plaza del Encuentro%^RESET%^\n\n"
            "La calle se anchea en esta zona dando lugar a una placita estrecha y oscura, algunos "
            "ciudadanos pasean por los jardines y los perros corren de un lado a otro detras de "
            "algunos pajaros. Esta es la entrada a la parte mas peligrosa de la ciudad, los barrios "
            "bajos, que se encuentran al oeste de la ciudad.\n\n");


   crea_npcs_barrios_bajos();

add_exit("sudoeste",     BRETHEM + "plaza_encuentro3.c","standard");
add_exit("sur",          BRETHEM + "plaza_encuentro1.c","standard");
add_exit("sudeste",      BRETHEM + "gen19.c","standard");


}

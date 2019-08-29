/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^YELLOW%^Calle Bandor%^RESET%^");
   long_desc_barrios_bajos();


   crea_npcs_barrios_bajos();

add_exit("norte",        BRETHEM + "gen20.c","standard");
add_exit("noroeste",     BRETHEM + "bajos_entrada1.c","standard");
add_exit("oeste",        BRETHEM + "bandor2.c","standard");
add_exit("sudeste",      BRETHEM + "callejon3.c","standard");


}

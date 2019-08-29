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

add_exit("sudoeste",     BRETHEM + "nose.c","standard");
add_exit("noreste",      BRETHEM + "bandor9.c","standard");
add_exit("este",         BRETHEM + "parque_piedra5.c","standard");
add_exit("sudeste",      BRETHEM + "mar30.c","standard");

}

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

add_exit("oeste",        BRETHEM + "bandor3.c","standard");
add_exit("este",         BRETHEM + "bandor1.c","standard");
add_exit("dentro",       BRETHEM + "tienda_maru.c","standard");


}

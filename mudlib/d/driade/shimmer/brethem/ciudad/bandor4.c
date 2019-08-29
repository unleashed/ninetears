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

add_exit("oeste",        BRETHEM + "bandor5.c","standard");
add_exit("noreste",      BRETHEM + "bandor3.c","standard");
add_exit("sudeste",      BRETHEM + "mercado4.c","standard");

}

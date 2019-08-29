/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^MAGENTA%^Barrios Bajos%^RESET%^");
   long_desc_barrios_bajos();

   crea_npcs_barrios_bajos();

add_exit("oeste",      BRETHEM + "bajos5.c","standard");
add_exit("norte",      BRETHEM + "bajos13.c","standard");
add_exit("sudoeste",   BRETHEM + "bajos35.c","standard");
add_exit("este",       BRETHEM + "bajos3.c","standard");

}

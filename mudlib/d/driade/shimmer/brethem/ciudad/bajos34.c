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

add_exit("norte",      BRETHEM + "bajos6.c","standard");
add_exit("sur",        BRETHEM + "bajos40.c","standard");
add_exit("este",       BRETHEM + "bajos35.c","standard");
add_exit("oeste",      BRETHEM + "bajos33.c","standard");
add_exit("noreste",    BRETHEM + "bajos5.c","standard");
add_exit("sudoeste",   BRETHEM + "bajos39.c","standard");
}

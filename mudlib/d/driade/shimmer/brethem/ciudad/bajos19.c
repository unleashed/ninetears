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

add_exit("sur",        BRETHEM + "bajos15.c","standard");
add_exit("este",       BRETHEM + "bajos18.c","standard");
add_exit("oeste",      BRETHEM + "bajos20.c","standard");

}

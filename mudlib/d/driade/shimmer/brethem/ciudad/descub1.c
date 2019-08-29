/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^YELLOW%^Calle del Descubridor%^RESET%^");
   long_desc();  

   crea_npcs();

add_exit("noroeste",       BRETHEM + "descub2.c","standard");
add_exit("sudeste",        BRETHEM + "gen16.c","standard");
add_exit("oeste",          BRETHEM + "monum1.c","standard");

}

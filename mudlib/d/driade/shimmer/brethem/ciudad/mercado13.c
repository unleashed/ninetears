/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {

   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Mercado de Brethem%^RESET%^");
   long_desc_mercado();


   crea_npcs_mercado();

add_exit("norte",        BRETHEM + "mercado8.c","standard");
add_exit("noreste",      BRETHEM + "mercado7.c","standard");
add_exit("oeste",        BRETHEM + "mercado14.c","standard");

}

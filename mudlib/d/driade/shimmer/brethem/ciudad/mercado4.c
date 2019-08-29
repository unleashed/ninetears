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

add_exit("oeste",       BRETHEM + "mercado5.c","standard");
add_exit("este",        BRETHEM + "mercado3.c","standard");
add_exit("noroeste",    BRETHEM + "bandor4.c","standard");

}

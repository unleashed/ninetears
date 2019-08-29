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

add_exit("norte",          BRETHEM + "mercado16.c","standard");
add_exit("noroeste",       BRETHEM + "mercado17.c","standard");
add_exit("oeste",          BRETHEM + "mercado21.c","standard");
add_exit("sur",            BRETHEM + "mar24.c","standard");
add_exit("noreste",        BRETHEM + "mercado15.c","standard");
add_exit("este",           BRETHEM + "mercado19.c","standard");


}

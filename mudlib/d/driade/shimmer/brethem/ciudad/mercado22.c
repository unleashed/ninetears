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

add_exit("norte",          BRETHEM + "mercado18.c","standard");
add_exit("oeste",          BRETHEM + "parque_piedra1.c","standard");
add_exit("sudoeste",       BRETHEM + "mercado24.c","standard");
add_exit("este",           BRETHEM + "mercado21.c","standard");



}

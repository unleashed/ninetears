/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^BLACK%^Calle del Monumento%^RESET%^");
   long_desc_monumento();  

   crea_npcs();

add_exit("noroeste",           BRETHEM + "monum13.c","standard");
add_exit("este",               BRETHEM + "monum11.c","standard");


}

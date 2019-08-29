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

add_exit("oeste",              BRETHEM + "monum10.c","standard");
add_exit("noreste",            BRETHEM + "monum8.c","standard");


}

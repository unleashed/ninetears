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

add_exit("oeste",          BRETHEM + "monum5.c","standard");
add_exit("sudeste",        BRETHEM + "monum3.c","standard");


}

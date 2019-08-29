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

add_exit("noroeste",       BRETHEM + "descub5.c","standard");
add_exit("sur",            BRETHEM + "descub3.c","standard");


}

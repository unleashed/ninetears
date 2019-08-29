/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Calle del Mar%^RESET%^");
   long_desc();  

   crea_npcs();

add_exit("norte",     BRETHEM + "estatualeon.c","standard");
add_exit("oeste",     BRETHEM + "parque10.c","standard");
add_exit("sur",       BRETHEM + "mar1.c","standard");

}

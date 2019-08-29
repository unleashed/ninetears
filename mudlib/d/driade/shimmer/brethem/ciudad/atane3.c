/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BLUE%^Calle Atane%^RESET%^");
   long_desc();  

   crea_npcs();

add_exit("sudoeste", BRETHEM + "atane2.c","standard");
add_exit("noreste",  BRETHEM + "mied6.c","standard");
add_exit("sur",      BRETHEM + "rueiro3.c","standard");

}

/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Calle Rueiro%^RESET%^");
   long_desc_callejon();  

   crea_npcs_callejon();


add_exit("norte",    BRETHEM + "rueiro3.c","standard");
add_exit("sur",      BRETHEM + "rueiro1.c","standard");

}

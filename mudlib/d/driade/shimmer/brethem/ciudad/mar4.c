/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Calle del Mar%^RESET%^");
   long_desc_callemar();  

   crea_npcs_callemar();

add_exit("oeste",     BRETHEM + "mar5.c","standard");
add_exit("este",      BRETHEM + "mar3.c","standard");

}

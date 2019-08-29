/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Calle del Manco%^RESET%^");
   long_desc_callejon();  

   crea_npcs_callejon();

add_exit("oeste",       BRETHEM + "barr3.c","standard");
add_exit("sudeste",     BRETHEM + "manco2.c","standard");


}

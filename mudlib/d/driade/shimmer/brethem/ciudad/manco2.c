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

add_exit("noroeste",    BRETHEM + "manco3.c","standard");
add_exit("sudeste",     BRETHEM + "manco1.c","standard");
add_exit("norte",       BRETHEM + "nose.c","standard");


}

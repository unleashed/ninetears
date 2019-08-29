/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^RED%^Calle Embarrada%^RESET%^");
   long_desc_callejon();  

   crea_npcs_callejon();

add_exit("noroeste",    BRETHEM + "mied1.c","standard");
add_exit("sur",         BRETHEM + "barr2.c","standard");
add_exit("este",        BRETHEM + "manco3.c","standard");

}

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

add_exit("norte",       BRETHEM + "barr3.c","standard");
add_exit("sur",         BRETHEM + "barr1.c","standard");


}

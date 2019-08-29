/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";

void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^%^BLACK%^Calle del Miedo%^RESET%^");
   long_desc();  

   crea_npcs();

add_exit("oeste",    BRETHEM + "mied2.c","standard");
add_exit("este",     BRETHEM + "nose.c","standard");
add_exit("norte",    BRETHEM + "nose.c","standard");
add_exit("sudeste",  BRETHEM + "barr3.c","standard");

}

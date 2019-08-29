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

add_exit("noroeste",     BRETHEM + "mied9.c","standard");
add_exit("este",         BRETHEM + "mied7.c","standard");
add_exit("oeste",        BRETHEM + "callejon1.c","standard");

}

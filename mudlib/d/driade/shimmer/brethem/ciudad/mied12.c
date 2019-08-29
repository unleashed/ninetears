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

add_exit("oeste",        BRETHEM + "mied13.c","standard");
add_exit("este",         BRETHEM + "mied11.c","standard");
add_exit("prision",      BRETHEM + "prision1.c","standard");

}

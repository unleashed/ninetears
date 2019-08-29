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

add_exit("oeste",    BRETHEM + "mied4.c","standard");
add_exit("este",     BRETHEM + "mied2.c","standard");
add_exit("dentro",   BRETHEM + "cuartel1.c","standard");


}

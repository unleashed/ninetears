/* By Shimmer */

#define CREATOR "shimmer"

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("blue");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Puerto%^RESET%^");
   long_desc_puerto();  

   crea_npcs_puerto();

add_exit("noroeste",     BRETHEM + "puerto24.c","standard");
add_exit("sudeste",      BRETHEM + "puerto22.c","standard");
add_exit("este",         BRETHEM + "puerto9.c","standard");
 

}

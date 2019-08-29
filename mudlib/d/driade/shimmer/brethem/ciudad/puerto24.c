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

add_exit("oeste",        BRETHEM + "puerto25.c","standard");
add_exit("sudeste",      BRETHEM + "puerto23.c","standard");
add_exit("norte",        BRETHEM + "puerto7.c","standard");
 

}

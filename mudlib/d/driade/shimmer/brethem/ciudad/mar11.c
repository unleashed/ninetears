/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Calle del Mar%^RESET%^");
   long_desc_callemar();  

   crea_npcs_callemar();

add_exit("oeste",       BRETHEM + "mar12.c","standard");
add_exit("noreste",     BRETHEM + "mar10.c","standard");
add_exit("noroeste",    BRETHEM + "callebiblioteca.c","standard");

}

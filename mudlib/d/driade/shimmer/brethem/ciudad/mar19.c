/* By Shimmer */

#include "../../path.h"

inherit BRETHEM+"cityroom.c";


void setup() {
   
   base_desc();
   set_exit_color("cyan");
   set_short("%^BOLD%^Ciudad de Brethem : %^BOLD%^BLUE%^Calle del Mar, Entrada al Puerto%^RESET%^");
   long_desc_callemar();  

   crea_npcs_callemar();

add_exit("sudoeste",    BRETHEM + "mar20.c","standard");
add_exit("norte",       BRETHEM + "mar18.c","standard");
add_exit("este",        BRETHEM + "puerto1.c","standard");


}
